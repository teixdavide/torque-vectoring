#pragma once

#include "high_level_controllers/high_level_controller.hpp"
#include <algorithm>

/**
 * @brief A PID + feedforward controller for yaw moment control in a torque vectoring system.
 * 
 * This controller includes:
 *  - PID yaw-rate tracking
 *  - Feedforward yaw moment using Iz * d(yaw_rate)/dt
 *  - First-order filtering of yaw acceleration (1 / (tau s + 1))
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
     * @param integral_limit Maximum absolute value for the integral term
     * @param tau Time constant for yaw acceleration filtering
     */
    PIDController(const CarParameters& car_params,
                  double kp,
                  double ki,
                  double kd,
                  double dt,
                  double integral_limit,
                  double tau);   // <-- NEW

    /**
     * @brief Compute the control output
     */
    YawMomentTorqueRequest compute_control(const VehicleState& state,
                                           const Reference& reference,
                                           const DriverCommand& driver_command) override;

    /**
     * @brief Reset controller state
     */
    void reset();

private:
    // ===============================
    // PID gains
    // ===============================
    double kp_;
    double ki_;
    double kd_;

    // ===============================
    // Timing
    // ===============================
    double dt_;

    // ===============================
    // PID state
    // ===============================
    double integral_error_;
    double previous_error_;

    double integral_limit_;

    // ===============================
    // Feedforward (Iz * s)
    // ===============================
    double previous_yaw_rate_ref_;   ///< Needed to compute derivative

    // ===============================
    // Low-pass filter (1 / (tau s + 1))
    // ===============================
    double tau_;                    ///< Filter time constant
    double yaw_acc_filtered_;       ///< Filtered yaw acceleration
};