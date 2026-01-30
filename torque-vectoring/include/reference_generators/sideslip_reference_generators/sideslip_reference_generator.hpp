#pragma once
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/car_parameters.hpp"

class SideslipReferenceGenerator {
  public:
    virtual ~SideslipReferenceGenerator() = default;
    virtual double generate_reference_sideslip(VehicleState state, DriverCommand command, double reference_yaw_rate) = 0;
};