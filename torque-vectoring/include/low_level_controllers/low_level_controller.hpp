#pragma once

#include "data_structures/car_parameters.hpp"
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"   
#include "data_structures/yaw_moment_torque_request.hpp"
#include "data_structures/torque_output.hpp"

class LowLevelController {
  public:
    /**
     * @brief Construct a new Low Level Controller object
     * 
     * @param car_params Vehicle parameters
     */
    explicit LowLevelController(const CarParameters& car_params) 
        : car_params_(car_params) {};

    /**
     * @brief Destroy the Low Level Controller object
     * 
     */
    virtual ~LowLevelController() = default;

    /**
     * @brief Compute low-level control command
     * 
     * @param state Current VehicleState
     * @param driver_command DriverCommand containing desired throttle, brake, and steering inputs
     * @return YawMomentTorqueRequest Low-level control outputs (throttle, brake, steering)
     */
    virtual TorqueOutput compute_control(const YawMomentTorqueRequest& yaw_moment_torque_request) = 0;

  protected:
    CarParameters car_params_; ///< Vehicle parameters
};