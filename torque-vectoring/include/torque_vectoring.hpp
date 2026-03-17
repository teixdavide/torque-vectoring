#pragma once

#include "reference_generators/reference_generator.hpp"
#include "high_level_controllers/high_level_controller.hpp"
#include "low_level_controllers/low_level_controller.hpp"
#include <memory>

class TorqueVectoring {
  public:
    TorqueVectoring(const CarParameters& car_params,
                             std::shared_ptr<ReferenceGenerator> reference_generator,
                             std::shared_ptr<LowLevelController> low_level_controller,
                             std::shared_ptr<HighLevelController> high_level_controller);

    TorqueOutput compute_control(const VehicleState& state,
                                           const DriverCommand& driver_command);

  private:
    std::shared_ptr<ReferenceGenerator> reference_generator_; ///< Reference generator for desired states
    std::shared_ptr<LowLevelController> low_level_controller_; ///< Low-level controller for torque distribution
    std::shared_ptr<HighLevelController> high_level_controller_; ///< High-level controller for overall control strategy
};
