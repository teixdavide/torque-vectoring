#include "include/reference_generators/steady_state_reference_generator.hpp"
#include <cmath>

SteadyStateReferenceGenerator::SteadyStateReferenceGenerator(const CarParameters &car_params, bool overide_understeer, double understeer_coefficient)
{
    car_params_ = car_params;
    if (overide_understeer) {
        _understeer_coefficient_ = understeer_coefficient;
    } else {
        double m = car_params_.mass;
        double L = car_params_.front_axle_distance + car_params_.rear_axle_distance;
        double lr = car_params_.rear_axle_distance;
        double lf = car_params_.front_axle_distance;
        double Cf = car_params_.cornering_stiffness_front;
        double Cr = car_params_.cornering_stiffness_rear;

        _understeer_coefficient_ = (m / pow(L, 2)) * ((lr / Cf) - (lf / Cr));
    }
}

double SteadyStateReferenceGenerator::generate_reference_yaw_rate(VehicleState state, DriverCommand command)
{
    double Vx = state.velocity_x;
    double steering_angle = command.steering;

    if (Vx == 0) {
        return 0.0;
    }

    double yaw_rate = (Vx * steering_angle) / (car_params_.front_axle_distance + car_params_.rear_axle_distance + _understeer_coefficient_ * Vx * Vx);
    return yaw_rate;
}