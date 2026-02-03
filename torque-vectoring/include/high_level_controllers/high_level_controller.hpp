#pragma once

#include "data_structures/car_parameters.hpp"
#include "data_structures/reference.hpp"
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/yaw_moment_torque_request.hpp"

/**
 * @brief High-level controller interface
 * 
 * Computes vehicle-level control commands (e.g. steering, torque requests)
 * based on the current vehicle state and desired references.
 */
class HighLevelController {
  public:
    /**
     * @brief Construct a new High Level Controller object
     * 
     * @param car_params Vehicle parameters
     */
    explicit HighLevelController(const CarParameters& car_params);

    virtual ~HighLevelController() = default;

    /**
     * @brief Compute high-level control command
     * 
     * @param state Current VehicleState
     * @param reference Desired Reference (yaw rate, sideslip, etc.)
     * @return YawMomentTorqueRequest High-level control outputs
     */
    virtual YawMomentTorqueRequest compute_control(const VehicleState& state,
                                                   const Reference& reference,
                                                   const DriverCommand& driver_command) = 0;

  protected:
    CarParameters car_params_; ///< Vehicle parameters
};
