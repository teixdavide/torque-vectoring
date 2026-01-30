#pragma once
#include "yaw_rate_reference_generator.hpp"
#include "car_parameters.hpp"

class SteadyStateYawRateReferenceGenerator : public YawRateReferenceGenerator {
  public:
    SteadyStateYawRateReferenceGenerator(const CarParameters& car_params, bool override_understeer = false, double understeer_coefficient_ = 0.0);
    double generate_reference_yaw_rate(VehicleState state, DriverCommand command) override;

  private:
    CarParameters car_parameters_;
    double understeer_coefficient_;
};