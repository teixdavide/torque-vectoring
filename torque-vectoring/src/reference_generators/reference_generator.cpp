#include "reference_generators/reference_generator.hpp"

ReferenceGenerator::ReferenceGenerator(YawRateReferenceGenerator* yaw_rate_generator,
                                       SideslipReferenceGenerator* sideslip_generator) : 
    yaw_rate_generator_(yaw_rate_generator),
    sideslip_generator_(sideslip_generator) {}

Reference ReferenceGenerator::create_reference(VehicleState state, DriverCommand command) {
    double reference_yaw_rate = yaw_rate_generator_->generate_reference_yaw_rate(state, command);
    double reference_sideslip = sideslip_generator_->generate_reference_sideslip(state, command, reference_yaw_rate);
    Reference reference;
    reference.yaw_rate = reference_yaw_rate;
    reference.sideslip_angle = reference_sideslip;
    return reference;
}