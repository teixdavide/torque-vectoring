#include "high_level_controllers/pid_controller.hpp"
#include "rclcpp/rclcpp.hpp"
#include <algorithm>

PIDController::PIDController(const CarParameters& car_params,
                             double kp,
                             double ki,
                             double kd,
                             double dt,
                             double integral_limit,
                             double tau)   // <-- NEW: filter time constant
    : HighLevelController(car_params),
      kp_(kp),
      ki_(ki),
      kd_(kd),
      dt_(dt),
      tau_(tau),
      integral_error_(0.0),
      previous_error_(0.0),
      previous_yaw_rate_ref_(0.0),
      yaw_acc_filtered_(0.0),
      integral_limit_(integral_limit) {


      }

void PIDController::reset() {
    integral_error_ = 0.0;
    previous_error_ = 0.0;
    previous_yaw_rate_ref_ = 0.0;
    yaw_acc_filtered_ = 0.0;
}

YawMomentTorqueRequest PIDController::compute_control(
    const VehicleState& state,
    const Reference& reference,
    const DriverCommand& driver_command) {

    double v = state.velocity_x;

    //v = std::min(v, 32.0);

    //kp_ = 1.67 * v - 8.76;
    //ki_ = -0.23 * v + 9.95;

    //kp_ = std::max(kp_, 0.0);
    //ki_ = std::max(ki_, 0.0);


    YawMomentTorqueRequest request{};

    // ===============================
    // 1. Yaw-rate tracking (PID)
    // ===============================
    const double error = reference.yaw_rate - state.yaw_rate;

    // Integral with anti-windup
    integral_error_ += error * dt_;
    integral_error_ = std::clamp(integral_error_,
                                -integral_limit_,
                                 integral_limit_);

    // Derivative
    const double derivative_error = (error - previous_error_) / dt_;
    previous_error_ = error;

    // PID yaw moment
    const double mz_pi =
        kp_ * error +
        ki_ * integral_error_ +
        kd_ * derivative_error;

    // ===============================
    // 2. Feedforward (Iz * s block)
    // ===============================

    // Raw yaw acceleration (derivative of reference yaw rate)
    const double yaw_acc_raw =
        (reference.yaw_rate - previous_yaw_rate_ref_) / dt_;

    previous_yaw_rate_ref_ = reference.yaw_rate;

    // Low-pass filter: 1 / (tau s + 1)
    //yaw_acc_filtered_ +=
    //    (dt_ / tau_) * (yaw_acc_raw - yaw_acc_filtered_);

    // Feedforward yaw moment
    const double mz_ff =
        car_params_.moment_of_inertia_z * yaw_acc_filtered_;

    // ===============================
    // 3. Combine (PI + Feedforward)
    // ===============================
    double yaw_moment = mz_pi + mz_ff;

    // Saturation
    yaw_moment = std::clamp(
        yaw_moment,
        -car_params_.max_yaw_moment,
         car_params_.max_yaw_moment
    );

    request.yaw_moment = yaw_moment;

    // ===============================
    // 4. Total longitudinal torque
    // ===============================
    request.total_torque = std::clamp(
        driver_command.throttle * car_params_.max_drive_torque,
        -car_params_.max_brake_torque,
         car_params_.max_drive_torque
    );

    return request;
}