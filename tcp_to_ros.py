import socket
import threading
import numpy as np
import rclpy

from rclpy.node import Node
from std_msgs.msg import Float64, Float64MultiArray
from geometry_msgs.msg import Vector3

HOST = '0.0.0.0'
PORT_IN = 20000      # Simulink -> ROS
PORT_OUT = 20001     # ROS -> Simulink
BUFFER_SIZE = 4096


class TCPBridge(Node):

    def __init__(self):
        super().__init__('tcp_vehicle_bridge')

        # Publishers
        self.throttle_pub = self.create_publisher(Float64, '/vehicle/throttle', 10)
        self.steering_pub = self.create_publisher(Float64, '/vehicle/steering', 10)
        self.yawrate_pub = self.create_publisher(Float64, '/vehicle/yaw_rate', 10)
        self.velocity_pub = self.create_publisher(Vector3, '/vehicle/velocity', 10)
        self.accel_pub = self.create_publisher(Vector3, '/vehicle/acceleration', 10)

        # Subscriber (NEW)
        self.torque_sub = self.create_subscription(
            Float64MultiArray,
            '/vehicle/wheel_torques',
            self.torque_callback,
            10
        )

        self.vel_x = 0.0
        self.client_out = None

        # Start threads
        threading.Thread(target=self.start_input_server, daemon=True).start()
        threading.Thread(target=self.start_output_server, daemon=True).start()

    # =========================
    # 🔹 INPUT: Simulink → ROS
    # =========================
    def start_input_server(self):

        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind((HOST, PORT_IN))
        server_socket.listen(1)

        self.get_logger().info(f"Input server listening on {PORT_IN}")

        conn, addr = server_socket.accept()
        self.get_logger().info(f"Input connected by {addr}")

        while rclpy.ok():
            data = conn.recv(BUFFER_SIZE)

            if not data:
                break

            uint64_values = np.frombuffer(data, dtype=np.uint64)
            values = uint64_values.view(np.float64)

            if len(values) == 0:
                continue

            flag = int(values[0])

            # TYPE 0
            if flag == 0 and len(values) >= 3:
                throttle, steering = values[1:3]

                msg_t = Float64()
                msg_s = Float64()

                msg_t.data = throttle
                msg_s.data = steering

                self.throttle_pub.publish(msg_t)
                self.steering_pub.publish(msg_s)

            # TYPE 1
            elif flag == 1 and len(values) >= 3:
                yaw = Float64()
                yaw.data = values[1]

                self.vel_x = values[2]

                self.yawrate_pub.publish(yaw)

            # TYPE 2
            elif flag == 2 and len(values) >= 5:
                vx, vy, ax, ay = values[1:5]

                vel = Vector3()
                vel.x = self.vel_x
                vel.y = vy

                acc = Vector3()
                acc.x = ax
                acc.y = ay

                self.velocity_pub.publish(vel)
                self.accel_pub.publish(acc)

    # =========================
    # 🔹 OUTPUT: ROS → Simulink
    # =========================
    def start_output_server(self):

        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind((HOST, PORT_OUT))
        server_socket.listen(1)

        self.get_logger().info(f"Output server listening on {PORT_OUT}")

        self.client_out, addr = server_socket.accept()
        self.get_logger().info(f"Output connected by {addr}")

    def torque_callback(self, msg: Float64MultiArray):

        if self.client_out is None:
            return

        try:
            # Convert torques to float64 array
            data = np.array(msg.data, dtype=np.float64)

            # Optional: add flag for Simulink parsing
            packet = np.concatenate(([10.0], data))  # flag=10

            self.client_out.sendall(packet.tobytes())

        except Exception as e:
            self.get_logger().warn(f"Send failed: {e}")


def main(args=None):

    rclpy.init(args=args)

    node = TCPBridge()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass

    node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()