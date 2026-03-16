#include "TorqueVectoringNode.hpp"

TorqueVectoringNode::TorqueVectoringNode()
: Node("torque_vectoring_node")
{
    // --- Subscribers ---
    throttle_sub_ = this->create_subscription<std_msgs::msg::Float64>(
        "/vehicle/throttle", 10,
        std::bind(&TorqueVectoringNode::throttleCallback, this, std::placeholders::_1));

    steering_sub_ = this->create_subscription<std_msgs::msg::Float64>(
        "/vehicle/steering", 10,
        std::bind(&TorqueVectoringNode::steeringCallback, this, std::placeholders::_1));

    yawrate_sub_ = this->create_subscription<std_msgs::msg::Float64>(
        "/vehicle/yaw_rate", 10,
        std::bind(&TorqueVectoringNode::yawRateCallback, this, std::placeholders::_1));

    velocity_sub_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/vehicle/velocity", 10,
        std::bind(&TorqueVectoringNode::velocityCallback, this, std::placeholders::_1));

    accel_sub_ = this->create_subscription<geometry_msgs::msg::Vector3>(
        "/vehicle/acceleration", 10,
        std::bind(&TorqueVectoringNode::accelCallback, this, std::placeholders::_1));

    // --- Publisher ---
    torque_pub_ = this->create_publisher<geometry_msgs::msg::Vector3>(
        "/vehicle/wheel_torques", 10);

    // --- Car parameters ---
    car_params_.mass = 269.6;
    car_params_.front_axle_distance = 1.20;
    car_params_.rear_axle_distance = 1.20;
    car_params_.cornering_stiffness_front = 127;
    car_params_.cornering_stiffness_rear = 127;
    car_params_.max_lateral_acceleration = 1.48 * 9.81;
    car_params_.max_yaw_moment = 150.0;
    car_params_.max_drive_torque = 400.0;
    car_params_.max_brake_torque = 300.0;

    // --- Initialize torque vectoring ---
    torque_vectoring_ = std::make_shared<TorqueVectoring>(car_params_);

    // --- Timer ---
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(10),
        std::bind(&TorqueVectoringNode::controlLoop, this));
}

// --- Callbacks ---
void TorqueVectoringNode::throttleCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    command_.throttle = msg->data;
}

void TorqueVectoringNode::steeringCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    command_.steering = msg->data;
}

void TorqueVectoringNode::yawRateCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    state_.yaw_rate = msg->data;
}

void TorqueVectoringNode::velocityCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    state_.velocity_x = msg->x;
    state_.velocity_y = msg->y;
}

void TorqueVectoringNode::accelCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    state_.acceleration_x = msg->x;
    state_.acceleration_y = msg->y;
}

// --- Control loop ---
void TorqueVectoringNode::controlLoop()
{
    auto output = torque_vectoring_->compute(state_, command_);

    geometry_msgs::msg::Vector3 torque_msg;

    torque_msg.x = output.rl_torque;
    torque_msg.y = output.rr_torque;
    torque_msg.z = output.fl_torque + output.fr_torque; // front torque sum

    torque_pub_->publish(torque_msg);
}

// --- main ---
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TorqueVectoringNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}