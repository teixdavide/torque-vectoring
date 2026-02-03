#pragma once
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/car_parameters.hpp"

/**
 * @brief Yaw Rate Reference Generator Interface
 * 
 */
class YawRateReferenceGenerator {
  public:
    /**
     * @brief Destroy the Yaw Rate Reference Generator object
     * 
     */
    virtual ~YawRateReferenceGenerator() = default;
    /**
     * @brief Generate a reference yaw rate based on the vehicle state and driver command
     * 
     * @param state Current VehicleState
     * @param command Current DriverCommand
     * @return double Reference yaw rate
     */
    virtual double generate_reference_yaw_rate(VehicleState state, DriverCommand command) = 0;
};