#pragma once

/**
 * @brief Structure to hold various car parameters used in vehicle dynamics and control.
 * 
 */
struct CarParameters {
  double front_axle_distance; ///< Distance from CG to front axle
  double rear_axle_distance; ///< Distance from CG to rear axle
  double front_track_width; ///< Front track width
  double rear_track_width;  ///< Rear track width
  double center_of_gravity_height; ///< Height of the center of gravity
  double mass; ///< Vehicle mass
  double moment_of_inertia_z; ///< Yaw moment of inertia
  double wheel_radius; ///< Wheel radius
  double gear_ratio; ///< Drivetrain gear ratio
  double inner_steering_ratio; ///< Inner wheel steering ratio
  double outer_steering_ratio; ///< Outer wheel steering ratio
  double cornering_stiffness_front; ///< Front cornering stiffness
  double cornering_stiffness_rear; ///< Rear cornering stiffness
  double max_lateral_acceleration; ///< Maximum lateral acceleration

  double max_drive_torque; ///< Maximum drive torque
  double max_brake_torque; ///< Maximum brake torque
  double max_yaw_moment; ///< Maximum yaw moment

  /**
   * @brief Tire model parameters
   * 
   */
  struct TireParameters {
    double lateral_stiffness_factor; ///< Lateral stiffness factor
    double shape_factor; ///< Shape factor
    double peak_factor; ///< Peak factor
    double curvature_factor; ///< Curvature factor
  } tire_parameters; ///< Tire model parameters

  /**
   * @brief Aerodynamics parameters
   * 
   */
  struct AerodynamicsParameters { 
    double drag_coefficient; ///< Drag coefficient
    double frontal_area; ///< Frontal area
    double lift_coefficient; ///< Lift coefficient
    double center_of_pressure_distribution; ///< Center of pressure distribution
  } aerodynamics_parameters; ///< Aerodynamics parameters
};