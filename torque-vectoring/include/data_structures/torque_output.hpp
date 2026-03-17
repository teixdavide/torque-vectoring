#pragma once

/**
 * @brief Structure to hold torque output values for each wheel.
 */
struct TorqueOutput {
  double rl_torque; // Rear Left wheel torque
  double rr_torque; // Rear Right wheel torque
  double fl_torque; // Front Left wheel torque
  double fr_torque; // Front Right wheel torque
};