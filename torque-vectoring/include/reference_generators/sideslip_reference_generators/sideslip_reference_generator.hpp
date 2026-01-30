#pragma once
#include "vehicle_state.hpp"
#include "driver_command.hpp"
#include "car_parameters.hpp"

class SideslipReferenceGenerator {
  public:
    virtual ~SideslipReferenceGenerator() = default;
    virtual double generate_reference_sideslip(VehicleState state, DriverCommand command, double reference_yaw_rate) = 0;
};