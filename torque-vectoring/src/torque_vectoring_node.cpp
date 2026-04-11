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
    torque_pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
        "/vehicle/wheel_torques", 10);

    yaw_rate_ref_pub_ = this->create_publisher<std_msgs::msg::Float64>(
        "/vehicle/yaw_rate_reference", 10);

    sideslip_ref_pub_ = this->create_publisher<std_msgs::msg::Float64>(
        "/vehicle/sideslip_reference", 10);

    yaw_moment_request_pub_ = this->create_publisher<std_msgs::msg::Float64>(
        "/vehicle/yaw_moment_request", 10); 

    total_torque_request_pub_ = this->create_publisher<std_msgs::msg::Float64>(
        "/vehicle/total_torque_request", 10);

    // --- Car parameters ---
    car_params_.mass = 270.048;
    car_params_.front_axle_distance = 0.873;
    car_params_.rear_axle_distance = 0.717;
    car_params_.front_track_width = 1.2;
    car_params_.rear_track_width = 1.2;
    car_params_.cornering_stiffness_front = 483;
    car_params_.cornering_stiffness_rear = 530;
    car_params_.max_lateral_acceleration = 1.6 * 9.81;
    car_params_.max_yaw_moment = 150.0;
    car_params_.max_drive_torque = 63.2 * 13; // 63.2 Nm per wheel, 13 is the gear ratio
    car_params_.max_brake_torque = 684.0; // 684 Nm per wheel

    // --- Initialize torque vectoring ---
    auto yaw_rate_generator = std::make_shared<SteadyStateYawRateReferenceGenerator>(car_params_, true, 0.0);
    auto sideslip_generator = std::make_shared<SteadyStateSideslipReferenceGenerator>(car_params_);

    auto reference_generator = std::make_shared<ReferenceGenerator>(
        yaw_rate_generator,  // pass raw pointer to ReferenceGenerator
        sideslip_generator
    );
    auto low_level_controller = std::make_shared<SimpleApproach>(car_params_);
    auto high_level_controller = std::make_shared<PIDController>(car_params_, 49.0, 5.0, 0.0, 0.001, 10000.0);
    
    torque_vectoring_ = std::make_shared<TorqueVectoring>(car_params_, reference_generator, low_level_controller, high_level_controller);

    // --- Timer ---
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(1),
        std::bind(&TorqueVectoringNode::controlLoop, this));

    RCLCPP_INFO(this->get_logger(), "Finished constructor");
}

// --- Callbacks ---
void TorqueVectoringNode::throttleCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    command_.throttle = msg->data;
}

void TorqueVectoringNode::steeringCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    command_.steering = msg->data * 0.17255;
}

void TorqueVectoringNode::yawRateCallback(const std_msgs::msg::Float64::SharedPtr msg)
{
    state_.yaw_rate = msg->data;
}

void TorqueVectoringNode::velocityCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    state_.velocity_x = msg->x;
    state_.velocity_y = msg->y;
    received_velocity = true;
}

void TorqueVectoringNode::accelCallback(const geometry_msgs::msg::Vector3::SharedPtr msg)
{
    state_.acceleration_x = msg->x;
    state_.acceleration_y = msg->y;
}

// --- Control loop ---
void TorqueVectoringNode::controlLoop()
{
    //if (!received_velocity) return;

    if (state_.velocity_x <= 0){
        state_.velocity_x = 0.1;
        //return;
    }

    // Unpack the tuple returned by compute_control
    auto [torque_output, reference, yaw_request] = torque_vectoring_->compute_control(state_, command_);

     RCLCPP_INFO(rclcpp::get_logger("tv"), "Called all");

    std_msgs::msg::Float64MultiArray torque_msg;

    torque_msg.data.push_back(torque_output.rl_torque);
    torque_msg.data.push_back(torque_output.rr_torque);

    torque_pub_->publish(torque_msg);

    RCLCPP_INFO(rclcpp::get_logger("tv"), "Published data");

    // Publish reference and request for debugging/analysis
    std_msgs::msg::Float64 yaw_rate_ref_msg;
    yaw_rate_ref_msg.data = reference.yaw_rate;
    yaw_rate_ref_pub_->publish(yaw_rate_ref_msg);

    std_msgs::msg::Float64 sideslip_ref_msg;
    sideslip_ref_msg.data = reference.sideslip_angle;
    sideslip_ref_pub_->publish(sideslip_ref_msg);

    std_msgs::msg::Float64 yaw_moment_request_msg;
    yaw_moment_request_msg.data = yaw_request.yaw_moment;
    yaw_moment_request_pub_->publish(yaw_moment_request_msg);

    std_msgs::msg::Float64 total_torque_request_msg;
    total_torque_request_msg.data = yaw_request.total_torque;
    total_torque_request_pub_->publish(total_torque_request_msg);
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