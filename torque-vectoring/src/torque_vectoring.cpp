#include "torque_vectoring.hpp"

TorqueVectoring::TorqueVectoring(const CarParameters& car_params,
                             std::shared_ptr<ReferenceGenerator> reference_generator,
                             std::shared_ptr<LowLevelController> low_level_controller,
                             std::shared_ptr<HighLevelController> high_level_controller)
    : reference_generator_(reference_generator),
      low_level_controller_(low_level_controller),
      high_level_controller_(high_level_controller) {}

TorqueOutput TorqueVectoring::compute_control(const VehicleState& state,
                                           const Reference& reference,
                                           const DriverCommand& driver_command) {

    Reference desired_reference = reference_generator_->create_reference(state, driver_command);
    YawMomentTorqueRequest high_level_request = high_level_controller_->compute_control(state, desired_reference, driver_command);
    TorqueOutput torque_output = low_level_controller_->compute_control(high_level_request);
    return torque_output;
}