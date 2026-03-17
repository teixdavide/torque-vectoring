#pragma once
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/car_parameters.hpp"

/**
 * @brief Abstract base class for sideslip reference generators
 * 
 */
class SideslipReferenceGenerator {
  public:
    /**
     * @brief Destroy the Sideslip Reference Generator object
     * 
     */
    virtual ~SideslipReferenceGenerator() = default;
    
    /**
     * @brief Generate a reference sideslip angle
     * 
     * @param state Current vehicle state
     * @param command Current driver command
     * @param reference_yaw_rate Reference yaw rate
     * @return double Reference sideslip angle in radians
     */
    virtual double generate_reference_sideslip(VehicleState state, DriverCommand command, double reference_yaw_rate) = 0;
};