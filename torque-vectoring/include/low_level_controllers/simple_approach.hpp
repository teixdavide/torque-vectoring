#include "low_level_controllers/low_level_controller.hpp"

class SimpleApproach : public LowLevelController {
  public:
    /**
     * @brief Construct a new Simple Approach object
     * 
     * @param car_params Vehicle parameters
     */
    explicit SimpleApproach(const CarParameters& car_params) 
        : LowLevelController(car_params) {};

    /**
     * @brief Compute low-level control command using a simple approach
     * 
     * @param yaw_moment_torque_request YawMomentTorqueRequest containing desired yaw moment and torque
     * @return TorqueOutput Low-level control outputs (throttle, brake, steering)
     */
    TorqueOutput compute_control(const YawMomentTorqueRequest& yaw_moment_torque_request) override;
};