#pragma once

#include "high_level_controllers/high_level_controller.hpp"
#include <algorithm>

/**
 * @brief A PID controller for yaw moment control in a torque vectoring system.
 * 
 */
class PIDController : public HighLevelController {
public:
    /**
     * @brief Construct a new PID Controller object
     * 
     * @param car_params Vehicle parameters
     * @param kp Proportional gain
     * @param ki Integral gain
     * @param kd Derivative gain
     * @param dt Time step for integration and differentiation
     * @param integral_limit Maximum absolute value for the integral term to prevent windup
     */
    PIDController(const CarParameters& car_params,
                  double kp,
                  double ki,
                  double kd,
                  double dt,
                  double integral_limit);
    
    /**
     * @brief Compute the control output (yaw moment torque request) based on the current vehicle state, reference, and driver command.
     * 
     * @param state Current VehicleState
     * @param reference Desired Reference (yaw rate, sideslip)
     * @param driver_command Current DriverCommand (throttle, steering)
     * @return YawMomentTorqueRequest High-level control outputs (yaw moment torque and total drive torque)
     */
    YawMomentTorqueRequest compute_control(const VehicleState& state,
                                           const Reference& reference,
                                           const DriverCommand& driver_command) override;
    
    /**
     * @brief Reset the internal state of the PID controller (integral and previous error)
     * 
     */
    void reset();

private:
    double kp_; ///< Proportional gain
    double ki_; ///< Integral gain
    double kd_; ///< Derivative gain

    double dt_; ///< Time step for integration and differentiation

    double integral_error_; ///< Accumulated integral error
    double previous_error_; ///< Previous error for derivative calculation

    double integral_limit_; ///< Maximum absolute value for the integral term to prevent windup
};
