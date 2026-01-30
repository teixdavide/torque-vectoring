#pragma once
#include "vehicle_state.hpp"
#include "driver_command.hpp"
#include "car_parameters.hpp"

class YawRateReferenceGenerator {
  public:
    virtual ~YawRateReferenceGenerator() = default;
    virtual double generate_reference_yaw_rate(VehicleState state, DriverCommand command);
};