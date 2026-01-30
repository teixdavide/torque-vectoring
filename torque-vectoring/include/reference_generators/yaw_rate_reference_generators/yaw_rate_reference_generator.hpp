#pragma once
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/car_parameters.hpp"

class YawRateReferenceGenerator {
  public:
    virtual ~YawRateReferenceGenerator() = default;
    virtual double generate_reference_yaw_rate(VehicleState state, DriverCommand command) = 0;
};