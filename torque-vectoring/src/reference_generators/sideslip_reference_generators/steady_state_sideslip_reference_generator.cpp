#include "steady_state_sideslip_reference_generator.hpp"

SteadyStateSideslipReferenceGenerator::SteadyStateSideslipReferenceGenerator(const CarParameters& car_parameters)
    : car_parameters_(car_parameters) {}

double SteadyStateSideslipReferenceGenerator::generate_reference_sideslip(VehicleState state, DriverCommand command, double reference_yaw_rate) {
    double lr = car_parameters_.rear_axle_distance;
    double lf = car_parameters_.front_axle_distance;
    double L = lf + lr;
    double V = state.velocity_x;
    double m = car_parameters_.mass;
    double Cr = car_parameters_.cornering_stiffness_rear;

    if (V < 0.1) {
        return 0.0;
    }

    double beta_ss = (lr / V - (m * lf * V) / (L * Cr)) * reference_yaw_rate;

    return beta_ss;

}