#include "high_level_controllers/pid_controller.hpp"

PIDController::PIDController(const CarParameters& car_params,
                             double kp,
                             double ki,
                             double kd,
                             double dt,
                             double integral_limit)
    : HighLevelController(car_params),
      kp_(kp),
      ki_(ki),
      kd_(kd),
      dt_(dt),
      integral_error_(0.0),
      previous_error_(0.0),
      integral_limit_(integral_limit) {}

void PIDController::reset() {
    integral_error_ = 0.0;
    previous_error_ = 0.0;
}

YawMomentTorqueRequest PIDController::compute_control(
    const VehicleState& state,
    const Reference& reference,
    const DriverCommand& driver_command) {

    YawMomentTorqueRequest request{};

    // Yaw-rate tracking error
    const double error = reference.yaw_rate - state.yaw_rate;

    // Integral term with anti-windup
    integral_error_ += error * dt_;
    integral_error_ = std::clamp(integral_error_,
                                 -integral_limit_,
                                  integral_limit_);

    // Derivative term
    const double derivative_error = (error - previous_error_) / dt_;
    previous_error_ = error;

    // PID output (desired yaw moment)
    double yaw_moment =
        kp_ * error +
        ki_ * integral_error_ +
        kd_ * derivative_error;

    // Saturate yaw moment
    yaw_moment = std::clamp(
        yaw_moment,
        -car_params_.max_yaw_moment,
         car_params_.max_yaw_moment
    );

    request.yaw_moment = yaw_moment;

    // Longitudinal torque (simple mapping)
    request.total_torque = std::clamp(
        driver_command.throttle * car_params_.max_drive_torque,
        -car_params_.max_brake_torque,
         car_params_.max_drive_torque
    );

    return request;
}
