#include "reference_generators/reference_generator.hpp"
#include "rclcpp/rclcpp.hpp"


ReferenceGenerator::ReferenceGenerator(std::shared_ptr<SteadyStateYawRateReferenceGenerator> yaw,
                       std::shared_ptr<SteadyStateSideslipReferenceGenerator> sideslip) : 
    yaw_rate_generator_(yaw),
    sideslip_generator_(sideslip) {}

Reference ReferenceGenerator::create_reference(VehicleState state, DriverCommand command) {
    RCLCPP_INFO(rclcpp::get_logger("tv"), "Calling YR Generator");
    double reference_yaw_rate = yaw_rate_generator_->generate_reference_yaw_rate(state, command);
    RCLCPP_INFO(rclcpp::get_logger("tv"), "Called YR Generator");
    double reference_sideslip = sideslip_generator_->generate_reference_sideslip(state, command, reference_yaw_rate);
    RCLCPP_INFO(rclcpp::get_logger("tv"), "Called SS Generator");
    Reference reference;
    reference.yaw_rate = reference_yaw_rate;
    reference.sideslip_angle = reference_sideslip;
    return reference;
}