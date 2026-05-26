#pragma once
#include <algorithm>
#include "data_structures/car_parameters.hpp"
#include "data_structures/vehicle_state.hpp"
#include "data_structures/reference.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/torque_output.hpp"

class TractionControl {
public:
    TractionControl(const CarParameters& car_params,
                    double dt,
                    double slip_threshold  = 0.05,
                    double k_reduce        = 0.95,
                    double k_increase      = 1.02,
                    double slope_deadband  = 0.005);

    double compute_control(double slip_ratio, double driver_torque, VehicleState state);
    void reset();

private:
    double dt_;
    double slip_threshold_;   // TCS activates above this slip
    double k_reduce_;         // torque reduction factor when slope > 0 (past peak)
    double k_increase_;       // torque recovery factor when slope < 0 (before peak)
    double slope_deadband_;   // dead band around zero slope

    double previous_slip_;    // slip at previous timestep
    double torque_limit_;     // current torque limit applied by TCS
    bool   active_;           // TCS active flag
};