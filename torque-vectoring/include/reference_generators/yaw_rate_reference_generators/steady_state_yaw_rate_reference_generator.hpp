#pragma once
#include "reference_generators/yaw_rate_reference_generators/yaw_rate_reference_generator.hpp"
#include "data_structures/car_parameters.hpp"

/**
 * @brief Steady-State Yaw Rate Reference Generator
 * 
 */
class SteadyStateYawRateReferenceGenerator : public YawRateReferenceGenerator {
  public:
    
    /**
     * @brief Construct a new Steady State Yaw Rate Reference Generator object
     * 
     * @param car_params CarParameters struct containing vehicle parameters
     * @param override_understeer If true, use the provided understeer coefficient instead of calculating it
     * @param understeer_coefficient_ The understeer coefficient to use if override_understeer is true
     */
    SteadyStateYawRateReferenceGenerator(const CarParameters& car_params, bool override_understeer = false, double understeer_coefficient_ = 0.0);
    double generate_reference_yaw_rate(VehicleState state, DriverCommand command) override;

  private:
    CarParameters car_parameters_; ///< Vehicle parameters
    double understeer_coefficient_; ///< Understeer coefficient (Kus)
};