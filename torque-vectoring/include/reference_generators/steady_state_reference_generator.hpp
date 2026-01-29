#include "reference_generator.hpp"

class SteadyStateReferenceGenerator : public ReferenceGenerator
{
public:
    SteadyStateReferenceGenerator(const CarParameters &car_params, bool overide_understeer = false, double understeer_coefficient = 0.0);

protected:
    double generate_reference_yaw_rate(VehicleState state, DriverCommand command) override;
    double _understeer_coefficient_;
};