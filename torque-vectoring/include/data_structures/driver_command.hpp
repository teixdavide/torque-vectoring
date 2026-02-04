#pragma once

/**
 * @brief Structure to hold driver command inputs such as throttle and steering.
 * 
 */
struct DriverCommand {
  double throttle; ///< Throttle command (0.0 to 1.0)
  double steering; ///< Steering command (radians)
};