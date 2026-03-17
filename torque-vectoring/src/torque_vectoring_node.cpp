#include "torque_vectoring_node.hpp"
#include "reference_generators/yaw_rate_reference_generators/steady_state_yaw_rate_reference_generator.hpp"
#include "reference_generators/sideslip_reference_generators/steady_state_sideslip_reference_generator.hpp"
#include "low_level_controllers/simple_approach.hpp"
#include "high_level_controllers/pid_controller.hpp"


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
    auto yaw_rate_generator = std::make_shared<SteadyStateYawRateReferenceGenerator>(car_params_);
    auto sideslip_generator = std::make_shared<SteadyStateSideslipReferenceGenerator>(car_params_);
    auto reference_generator = std::make_shared<ReferenceGenerator>(yaw_rate_generator.get(), sideslip_generator.get());
    auto low_level_controller = std::make_shared<SimpleApproach>(car_params_);
    auto high_level_controller = std::make_shared<PIDController>(car_params_, 1.0, 0.1, 0.01, 0.01, 10.0);
    
    torque_vectoring_ = std::make_shared<TorqueVectoring>(car_params_, reference_generator, low_level_controller, high_level_controller);

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
    auto output = torque_vectoring_->compute_control(state_, command_);

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