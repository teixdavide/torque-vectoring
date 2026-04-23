import rclpy
from rclpy.node import Node

import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
import os
import time

from std_msgs.msg import Float64
from geometry_msgs.msg import Vector3

# =========================
# Hyperparameters
# =========================
STATE_DIM = 4
ACTION_DIM = 1
MAX_YAW_MOMENT = 150.0

GAMMA = 0.99
TAU = 0.005
LR_ACTOR = 1e-4
LR_CRITIC = 1e-3

MODEL_DIR = "models"
os.makedirs(MODEL_DIR, exist_ok=True)

# =========================
# Actor
# =========================
class Actor(nn.Module):
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(STATE_DIM, 128),
            nn.ReLU(),
            nn.Linear(128, 128),
            nn.ReLU(),
            nn.Linear(128, ACTION_DIM),
            nn.Tanh()
        )

    def forward(self, x):
        return self.net(x) * MAX_YAW_MOMENT


# =========================
# Critic
# =========================
class Critic(nn.Module):
    def __init__(self):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(STATE_DIM + ACTION_DIM, 128),
            nn.ReLU(),
            nn.Linear(128, 128),
            nn.ReLU(),
            nn.Linear(128, 1)
        )

    def forward(self, s, a):
        return self.net(torch.cat([s, a], dim=1))


# =========================
# Replay Buffer
# =========================
class ReplayBuffer:
    def __init__(self, max_size=100000):
        self.buffer = []
        self.max_size = max_size

    def add(self, data):
        if len(self.buffer) >= self.max_size:
            self.buffer.pop(0)
        self.buffer.append(data)

    def sample(self, batch_size):
        idx = np.random.choice(len(self.buffer), batch_size)
        batch = [self.buffer[i] for i in idx]

        s, a, r, s2 = zip(*batch)

        return (
            torch.FloatTensor(s),
            torch.FloatTensor(a),
            torch.FloatTensor(r).unsqueeze(1),
            torch.FloatTensor(s2)
        )


# =========================
# RL Agent
# =========================
class DDPG:
    def __init__(self):

        self.actor = Actor()
        self.actor_target = Actor()
        self.actor_target.load_state_dict(self.actor.state_dict())

        self.critic = Critic()
        self.critic_target = Critic()
        self.critic_target.load_state_dict(self.critic.state_dict())

        self.actor_opt = optim.Adam(self.actor.parameters(), lr=LR_ACTOR)
        self.critic_opt = optim.Adam(self.critic.parameters(), lr=LR_CRITIC)

        self.buffer = ReplayBuffer()

    def select_action(self, state):
        s = torch.FloatTensor(state).unsqueeze(0)
        return self.actor(s).detach().numpy()[0]

    def train(self, batch_size=64):
        if len(self.buffer.buffer) < batch_size:
            return

        s, a, r, s2 = self.buffer.sample(batch_size)

        with torch.no_grad():
            a2 = self.actor_target(s2)
            target_q = r + GAMMA * self.critic_target(s2, a2)

        current_q = self.critic(s, a)
        critic_loss = nn.MSELoss()(current_q, target_q)

        self.critic_opt.zero_grad()
        critic_loss.backward()
        self.critic_opt.step()

        actor_loss = -self.critic(s, self.actor(s)).mean()

        self.actor_opt.zero_grad()
        actor_loss.backward()
        self.actor_opt.step()

        # soft update
        for p, tp in zip(self.actor.parameters(), self.actor_target.parameters()):
            tp.data.copy_(TAU * p.data + (1 - TAU) * tp.data)

        for p, tp in zip(self.critic.parameters(), self.critic_target.parameters()):
            tp.data.copy_(TAU * p.data + (1 - TAU) * tp.data)

    def save(self):
        torch.save(self.actor.state_dict(), f"{MODEL_DIR}/actor.pth")
        torch.save(self.critic.state_dict(), f"{MODEL_DIR}/critic.pth")

    def load(self):
        try:
            self.actor.load_state_dict(torch.load(f"{MODEL_DIR}/actor.pth"))
            self.critic.load_state_dict(torch.load(f"{MODEL_DIR}/critic.pth"))
            print("Loaded existing model")
        except:
            print("No saved model found")


# =========================
# ROS2 NODE
# =========================
class RLNode(Node):

    def __init__(self):
        super().__init__("rl_torque_vectoring")

        # Subscribers
        self.create_subscription(Float64, "/vehicle/yaw_rate", self.yaw_cb, 10)
        self.create_subscription(Float64, "/vehicle/yaw_rate_reference", self.yaw_ref_cb, 10)
        self.create_subscription(Vector3, "/vehicle/velocity", self.vel_cb, 10)

        # Publisher
        self.pub = self.create_publisher(Float64, "/vehicle/yaw_moment_request", 10)

        # RL
        self.agent = DDPG()
        self.agent.load()

        # State
        self.vx = 0.1
        self.vy = 0.0
        self.yaw_rate = 0.0
        self.yaw_rate_ref = 0.0

        self.integral = 0.0
        self.prev_state = None

        self.dt = 0.01

        # Timer loop
        self.create_timer(self.dt, self.loop)

        self.step_count = 0

    # -----------------
    # Callbacks
    # -----------------
    def yaw_cb(self, msg):
        self.yaw_rate = msg.data

    def yaw_ref_cb(self, msg):
        self.yaw_rate_ref = msg.data

    def vel_cb(self, msg):
        self.vx = msg.x
        self.vy = msg.y

    # -----------------
    # Build state
    # -----------------
    def get_state(self):

        beta = np.arctan2(self.vy, max(self.vx, 0.1))

        yaw_error = self.yaw_rate_ref - self.yaw_rate
        self.integral += yaw_error * self.dt

        state = np.array([
            beta,
            yaw_error,
            self.integral,
            self.yaw_rate
        ], dtype=np.float32)

        return state, beta, yaw_error

    # -----------------
    # Reward
    # -----------------
    def compute_reward(self, beta, yaw_error, action):

        reward = (
            -10.0 * yaw_error**2
            -5.0 * beta**2
            -0.01 * action**2
        )

        if abs(beta) > 0.2:
            reward -= 5.0

        return reward

    # -----------------
    # Main loop
    # -----------------
    def loop(self):

        state, beta, yaw_error = self.get_state()

        action = self.agent.select_action(state)

        # exploration (can disable later)
        action += np.random.normal(0, 5.0)
        action = float(np.clip(action, -MAX_YAW_MOMENT, MAX_YAW_MOMENT))

        # Publish to ROS
        msg = Float64()
        msg.data = action
        self.pub.publish(msg)

        # Reward
        reward = self.compute_reward(beta, yaw_error, action)

        # Training
        if self.prev_state is not None:
            self.agent.buffer.add((self.prev_state, [action], reward, state))
            self.agent.train()

        self.prev_state = state

        # Save periodically
        self.step_count += 1
        if self.step_count % 5000 == 0:
            self.agent.save()
            self.get_logger().info("Model saved")

# =========================
# MAIN
# =========================
def main(args=None):
    rclpy.init(args=args)
    node = RLNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()