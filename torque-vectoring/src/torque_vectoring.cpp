#include "torque_vectoring.hpp"
#include "rclcpp/rclcpp.hpp"

TorqueVectoring::TorqueVectoring(const CarParameters& car_params,
                             std::shared_ptr<ReferenceGenerator> reference_generator,
                             std::shared_ptr<LowLevelController> low_level_controller,
                             std::shared_ptr<HighLevelController> high_level_controller)
    : reference_generator_(reference_generator),
      low_level_controller_(low_level_controller),
      high_level_controller_(high_level_controller) {}

TorqueOutput TorqueVectoring::compute_control(const VehicleState& state,
                                           const DriverCommand& driver_command) {
    RCLCPP_INFO(rclcpp::get_logger("tv"), "Calling Reference Generator");
    Reference desired_reference = reference_generator_->create_reference(state, driver_command);
    RCLCPP_INFO(rclcpp::get_logger("tv"), "Called Reference Generator");
    YawMomentTorqueRequest high_level_request = high_level_controller_->compute_control(state, desired_reference, driver_command);
    RCLCPP_INFO(rclcpp::get_logger("tv"), "Called HL Controllerr");
    TorqueOutput torque_output = low_level_controller_->compute_control(high_level_request);
    RCLCPP_INFO(rclcpp::get_logger("tv"), "Called LL Controllerr");
    return torque_output;
}