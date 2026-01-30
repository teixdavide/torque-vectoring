#pragma once
#include "data_structures/car_parameters.hpp"
#include "data_structures/reference.hpp"
#include "reference_generators/yaw_rate_reference_generators/yaw_rate_reference_generator.hpp"
#include "reference_generators/sideslip_reference_generators/sideslip_reference_generator.hpp"

class ReferenceGenerator {
  public:
    ReferenceGenerator(YawRateReferenceGenerator* yaw_rate_generator,
                       SideslipReferenceGenerator* sideslip_generator);
    Reference create_reference(VehicleState state, DriverCommand command);
  protected:
    YawRateReferenceGenerator* yaw_rate_generator_;
    SideslipReferenceGenerator* sideslip_generator_;
};