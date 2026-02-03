#pragma once
#include "data_structures/car_parameters.hpp"
#include "data_structures/reference.hpp"
#include "reference_generators/yaw_rate_reference_generators/yaw_rate_reference_generator.hpp"
#include "reference_generators/sideslip_reference_generators/sideslip_reference_generator.hpp"

/**
 * @brief Combines yaw rate and sideslip reference generators to produce a full Reference
 * 
 */
class ReferenceGenerator {
  public:
    /**
     * @brief Construct a new Reference Generator object
     * 
     * @param yaw_rate_generator Yaw Rate Reference Generator
     * @param sideslip_generator Sideslip Reference Generator
     */
    ReferenceGenerator(YawRateReferenceGenerator* yaw_rate_generator,
                       SideslipReferenceGenerator* sideslip_generator);
    
    /**
     * @brief Create a Reference struct containing both yaw rate and sideslip angle references
     * 
     * @param state Current VehicleState
     * @param command Current DriverCommand
     * @return Reference Struct containing reference yaw rate and sideslip angle
     */
    Reference create_reference(VehicleState state, DriverCommand command);
  protected:
    YawRateReferenceGenerator* yaw_rate_generator_; ///< Yaw Rate Reference Generator
    SideslipReferenceGenerator* sideslip_generator_; ///< Sideslip Reference Generator
};