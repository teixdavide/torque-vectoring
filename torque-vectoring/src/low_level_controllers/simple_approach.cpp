#include "low_level_controllers/simple_approach.hpp"

TorqueOutput SimpleApproach::compute_control(const YawMomentTorqueRequest& yaw_moment_torque_request) {
    TorqueOutput output;

    double delta_torque = yaw_moment_torque_request.yaw_moment / car_params_.rear_axle_distance;

    output.fl_torque = 0;
    output.fr_torque = 0;
    output.rl_torque = yaw_moment_torque_request.total_torque / 2 - delta_torque;
    output.rr_torque = yaw_moment_torque_request.total_torque / 2 + delta_torque;

    return output;
}