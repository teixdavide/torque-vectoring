#pragma once

/**
 * @brief Structure to hold the vehicle state parameters.
 * 
 */
struct VehicleState {
  double yaw_rate; ///< Yaw rate of the vehicle
  double sideslip_angle; ///< Sideslip angle of the vehicle
  double velocity_x; ///< Longitudinal velocity of the vehicle
  double velocity_y; ///< Lateral velocity of the vehicle
  double acceleration_x; ///< Longitudinal acceleration of the vehicle
  double acceleration_y; ///< Lateral acceleration of the vehicle
};