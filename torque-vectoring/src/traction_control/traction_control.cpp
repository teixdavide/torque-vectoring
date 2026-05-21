#include "traction_control/pid_controller.hpp"

TractionControl::TractionControl(const CarParameters& car_params,
                               double kp,
                               double ki,
                               double kd,
                               double dt,
                               double integral_limit,
                               double reference)
: kp_(kp), ki_(ki), kd_(kd), dt_(dt), integral_error_(0.0), previous_error_(0.0), integral_limit_(integral_limit)
{}

double TractionControl::compute_control(double slip_ratio, double driver_torque)
{
    double error = slip_ratio - 0.12;

    integral_error_ += error * dt_;
    integral_error_ = std::clamp(integral_error_, -integral_limit_, integral_limit_);

    double derivative_error = (error - previous_error_) / dt_;
    previous_error_ = error;

    double control_output = kp_ * error + ki_ * integral_error_ + kd_ * derivative_error;

    // Limit the control output to the driver's requested torque
    control_output = std::clamp(control_output, 0.0, driver_torque);

    return driver_torque - control_output;
}