#include "reference_generators/sideslip_reference_generators/sideslip_reference_generator.hpp"

/**
 * @brief Steady-state sideslip reference generator
 * 
 */
class SteadyStateSideslipReferenceGenerator : public SideslipReferenceGenerator {
  public:
    /**
     * @brief Construct a new Steady State Sideslip Reference Generator object
     * 
     * @param car_parameters Vehicle parameters
     */
    SteadyStateSideslipReferenceGenerator(const CarParameters& car_parameters);

    /**
     * @brief Generate a reference sideslip angle using steady-state vehicle model
     * 
     * @param state Current vehicle state
     * @param command Current driver command
     * @param reference_yaw_rate Reference yaw rate
     * @return double Reference sideslip angle in radians
     */
    double generate_reference_sideslip(VehicleState state, DriverCommand command, double reference_yaw_rate) override;
  private:
    CarParameters car_parameters_;
};