#pragma once
 
/**
 * @brief Yaw moment and total torque request data structure
 * 
 * Encapsulates the requested yaw moment torque and total drive torque.
 */
struct YawMomentTorqueRequest{
     double yaw_moment; ///< Requested yaw moment torque (Nm)
     double total_torque; ///< Total drive torque request (Nm)
 };