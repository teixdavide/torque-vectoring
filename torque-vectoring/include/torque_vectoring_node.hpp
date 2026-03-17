#pragma once

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/float64.hpp"
#include "geometry_msgs/msg/vector3.hpp"

#include "torque_vectoring.hpp"
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/reference.hpp"
#include "data_structures/car_parameters.hpp"

/**
 * @brief ROS2 Node for running Torque Vectoring with vehicle inputs
 *
 * Subscribes to throttle, steering, yaw rate, velocity, acceleration
 * Publishes rear/total wheel torques in a single topic
 */
class TorqueVectoringNode : public rclcpp::Node
{
public:
    TorqueVectoringNode();

private:
    // Subscribers
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr throttle_sub_;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr steering_sub_;
    rclcpp::Subscription<std_msgs::msg::Float64>::SharedPtr yawrate_sub_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr velocity_sub_;
    rclcpp::Subscription<geometry_msgs::msg::Vector3>::SharedPtr accel_sub_;

    // Publisher
    rclcpp::Publisher<geometry_msgs::msg::Vector3>::SharedPtr torque_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr yaw_rate_ref_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr sideslip_ref_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr yaw_moment_request_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr total_torque_request_pub_;

    // Timer for control loop
    rclcpp::TimerBase::SharedPtr timer_;

    // Vehicle / control data
    VehicleState state_;
    DriverCommand command_;
    Reference reference_;
    CarParameters car_params_;
    std::shared_ptr<TorqueVectoring> torque_vectoring_;

    // Callbacks
    void throttleCallback(const std_msgs::msg::Float64::SharedPtr msg);
    void steeringCallback(const std_msgs::msg::Float64::SharedPtr msg);
    void yawRateCallback(const std_msgs::msg::Float64::SharedPtr msg);
    void velocityCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);
    void accelCallback(const geometry_msgs::msg::Vector3::SharedPtr msg);

    // Control loop
    void controlLoop();
};