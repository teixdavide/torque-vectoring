#pragma once

/**
 * @brief Structure to hold reference values for vehicle dynamics.
 * 
 */
struct Reference {
    double yaw_rate; ///< Reference yaw rate (radians per second)
    double sideslip_angle; ///< Reference sideslip angle (radians)
};