#include "car_parameters.hpp"
#include "reference.hpp"
#include "vehicle_state.hpp"
#include "driver_command.hpp"

class ReferenceGenerator {
  public:
    virtual ~ReferenceGenerator() = default;
    Reference create_reference(VehicleState state, DriverCommand command);

  protected:
    CarParameters car_params_;
    virtual double generate_reference_yaw_rate(VehicleState state, DriverCommand command) = 0;
    double generate_reference_sideslip_angle(VehicleState state, DriverCommand command);
};