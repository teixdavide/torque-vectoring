#include "data_structures/sideslip_reference_generator.hpp"

class SteadyStateSideslipReferenceGenerator : public SideslipReferenceGenerator {
  public:
    SteadyStateSideslipReferenceGenerator(const CarParameters& car_parameters);
    double generate_reference_sideslip(VehicleState state, DriverCommand command, double reference_yaw_rate) override;
  private:
    CarParameters car_parameters_;
};