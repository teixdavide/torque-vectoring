#pragma once
#include "car_parameters.hpp"
#include "reference.hpp"
#include "yaw_rate_reference_generator.hpp"
#include "sideslip_reference_generator.hpp"

class ReferenceGenerator {
  public:
    ReferenceGenerator(YawRateReferenceGenerator* yaw_rate_generator,
                       SideslipReferenceGenerator* sideslip_generator);
    Reference create_reference(VehicleState state, DriverCommand command);
  protected:
    YawRateReferenceGenerator* yaw_rate_generator_;
    SideslipReferenceGenerator* sideslip_generator_;
};