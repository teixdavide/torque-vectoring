#include "torque_vectoring.hpp"
#include "rclcpp/rclcpp.hpp"
#include <tuple>

TorqueVectoring::TorqueVectoring(const CarParameters& car_params,
                                 std::shared_ptr<ReferenceGenerator> reference_generator,
                                 std::shared_ptr<LowLevelController> low_level_controller,
                                 std::shared_ptr<HighLevelController> high_level_controller)
    : reference_generator_(reference_generator),
      low_level_controller_(low_level_controller),
      high_level_controller_(high_level_controller) {}

// Updated function returning tuple: [TorqueOutput, Reference, YawMomentTorqueRequest]
std::tuple<TorqueOutput, Reference, YawMomentTorqueRequest> TorqueVectoring::compute_control(
    const VehicleState& state,
    const DriverCommand& driver_command) 
{
    // Generate desired reference
    Reference desired_reference = reference_generator_->create_reference(state, driver_command);

    // Compute high-level yaw moment torque request
    YawMomentTorqueRequest high_level_request = high_level_controller_->compute_control(
        state, desired_reference, driver_command);

     RCLCPP_INFO(rclcpp::get_logger("tv"), "Called HL Controller");

    // Compute low-level torque output
    TorqueOutput torque_output = low_level_controller_->compute_control(high_level_request);

    RCLCPP_INFO(rclcpp::get_logger("tv"), "Called LL Controller, RL:%f, RR:%f", torque_output.rl_torque, torque_output.rr_torque);

    // Return all three in a tuple
    return std::make_tuple(torque_output, desired_reference, high_level_request);
}