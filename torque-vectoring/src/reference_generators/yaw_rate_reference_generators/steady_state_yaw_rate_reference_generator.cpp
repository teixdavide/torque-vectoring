#include "reference_generators/yaw_rate_reference_generators/steady_state_yaw_rate_reference_generator.hpp"

SteadyStateYawRateReferenceGenerator::SteadyStateYawRateReferenceGenerator(
                                                const CarParameters& car_params, 
                                                bool override_understeer, 
                                                double understeer_coefficient)
    : car_parameters_(car_params) {

    if (override_understeer) {
        understeer_coefficient_ = understeer_coefficient;
    } else {
        double Cf = car_parameters_.cornering_stiffness_front;
        double Cr = car_parameters_.cornering_stiffness_rear;
        double lf = car_parameters_.front_axle_distance;
        double lr = car_parameters_.rear_axle_distance;
        double m = car_parameters_.mass;
        understeer_coefficient_ = m / (lr + lf) * (lr / Cf - lf / Cr);
    }
}

double SteadyStateYawRateReferenceGenerator::generate_reference_yaw_rate (
                                            VehicleState state, DriverCommand command) {
    
    // Needed parameters
    double L = car_parameters_.front_axle_distance + car_parameters_.rear_axle_distance;
    double V = state.velocity_x;
    double delta = command.steering;

    if (V < 0.1) {
        return 0.0;
    }


    double den = L + understeer_coefficient_ * V * V;

    if (den < 0) den = L;

    // Steady-state yaw rate calculation
    double yaw_rate_ref = V  / den * delta;

    // Limit yaw rate reference based on max lateral acceleration
    double a_y_max = car_parameters_.max_lateral_acceleration;
    double yaw_rate_limit = a_y_max / V;
    if (yaw_rate_ref > yaw_rate_limit) {
        yaw_rate_ref = yaw_rate_limit;
    } else if (yaw_rate_ref < -yaw_rate_limit) {
        yaw_rate_ref = -yaw_rate_limit;
    }

    return yaw_rate_ref;
}