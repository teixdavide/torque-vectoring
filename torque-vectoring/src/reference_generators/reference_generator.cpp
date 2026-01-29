#include "include/reference_generators/reference_generator.hpp"

Reference ReferenceGenerator::create_reference(VehicleState state, DriverCommand command)
{
    Reference ref;
    ref.yaw_rate = generate_reference_yaw_rate(state, command);
    ref.sideslip_angle = generate_reference_sideslip_angle(state, command);
    return ref;
}

double ReferenceGenerator::generate_reference_sideslip_angle(VehicleState state, DriverCommand command)
{
    double reference_yaw_rate = generate_reference_yaw_rate(state, command);

    double sideslip_angle = (car_params_.front_axle_distance / state.velocity_x -
                             (car_params_.mass * state.acceleration_x * state.velocity_x /
                              (car_params_.cornering_stiffness_rear *
                               (car_params_.front_axle_distance + car_params_.rear_axle_distance)))) *
                            reference_yaw_rate;

    return sideslip_angle;
}