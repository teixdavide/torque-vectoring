#pragma once
#include "data_structures/car_parameters.hpp"
#include "data_structures/reference.hpp"
#include <memory>
#include "reference_generators/yaw_rate_reference_generators/steady_state_yaw_rate_reference_generator.hpp"
#include "reference_generators/sideslip_reference_generators/steady_state_sideslip_reference_generator.hpp"

/**
 * @brief Combines yaw rate and sideslip reference generators to produce a full Reference
 * 
 */
class ReferenceGenerator {
    std::shared_ptr<SteadyStateYawRateReferenceGenerator> yaw_rate_generator_;
    std::shared_ptr<SteadyStateSideslipReferenceGenerator> sideslip_generator_;

public:
    ReferenceGenerator(std::shared_ptr<SteadyStateYawRateReferenceGenerator> yaw,
                       std::shared_ptr<SteadyStateSideslipReferenceGenerator> sideslip);

    Reference create_reference(VehicleState state, DriverCommand command);
};