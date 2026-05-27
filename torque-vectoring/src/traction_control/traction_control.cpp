#include "traction_control/traction_control.hpp"

TractionControl::TractionControl(const CarParameters& car_params,
                                 double dt,
                                 double slip_threshold,
                                 double k_reduce,
                                 double k_increase,
                                 double slope_deadband)
    : dt_(dt),
      slip_threshold_(slip_threshold),
      k_reduce_(k_reduce),
      k_increase_(k_increase),
      slope_deadband_(slope_deadband),
      previous_slip_(0.0), 
      torque_limit_(0.0),
      active_(false)
{}

double TractionControl::compute_control(double slip_ratio,
                                        double driver_torque,
                                        VehicleState state)
{
    // --- Low speed torque limits (launch control, unchanged from original) ---
    if (state.velocity_x < 1.0) return std::min(driver_torque, 41.08);
    if (state.velocity_x < 2.0) return std::min(driver_torque, 102.7);
    if (state.velocity_x < 4.0) return std::min(driver_torque, 143.78);
    if (state.velocity_x < 7.0) return std::min(driver_torque, 184.86);

    // --- Slip slope TCS ---
    // Compute slope of slip ratio over time
    double slip_slope = (slip_ratio - previous_slip_) / dt_;
    previous_slip_ = slip_ratio;

    if (!active_) {
        // TCS not active: pass driver torque through
        torque_limit_ = driver_torque;

        // Activate if slip exceeds threshold
        if (slip_ratio > slip_threshold_) {
            active_ = true;
        }
        return driver_torque;
    }

    // TCS active: deactivate if slip dropped back below threshold
    if (slip_ratio < slip_threshold_ * 0.8) {   // hysteresis band to avoid chattering
        active_ = false;
        torque_limit_ = driver_torque;
        return driver_torque;
    }

    // Slip slope logic (Gustafsson 1997):
    //   slope > +deadband → slip increasing → reduce torque (moving away from peak)
    //   slope < -deadband → slip decreasing → gently recover torque (approaching peak)
    //   |slope| <= deadband → at peak → hold torque
    if (slip_slope > slope_deadband_) {
        torque_limit_ *= k_reduce_;
    } else if (slip_slope < -slope_deadband_) {
        torque_limit_ *= k_increase_;
    }
    // else: hold torque_limit_ unchanged

    // Torque limit must stay within [0, driver_torque]
    torque_limit_ = std::clamp(torque_limit_, 0.0, driver_torque);

    return torque_limit_;
}

void TractionControl::reset()
{
    previous_slip_ = 0.0;
    torque_limit_  = 0.0;
    active_        = false;
}