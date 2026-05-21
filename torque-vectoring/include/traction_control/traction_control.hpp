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
                  double kp,
                  double ki,
                  double kd,
                  double dt,
                  double integral_limit,
                  double reference);


    double compute_control(double slip_ratio, double driver_torque);


    void reset();

private:
    double kp_;
    double ki_;
    double kd_;

    double dt_;

    double integral_error_;
    double previous_error_;

    double integral_limit_;
};