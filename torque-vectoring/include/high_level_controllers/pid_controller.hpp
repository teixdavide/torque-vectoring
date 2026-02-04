#pragma once

#include "high_level_controllers/high_level_controller.hpp"
#include <algorithm>

class PIDController : public HighLevelController {
public:
    PIDController(const CarParameters& car_params,
                  double kp,
                  double ki,
                  double kd,
                  double dt,
                  double integral_limit);

    YawMomentTorqueRequest compute_control(const VehicleState& state,
                                           const Reference& reference,
                                           const DriverCommand& driver_command) override;

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
