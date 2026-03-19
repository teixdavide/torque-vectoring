#pragma once

/**
 * @brief Structure to hold various car parameters used in vehicle dynamics and control.
 * 
 */
struct CarParameters {
  double front_axle_distance = 0.0; ///< Distance from CG to front axle
  double rear_axle_distance = 0.0; ///< Distance from CG to rear axle
  double front_track_width = 0.0; ///< Front track width
  double rear_track_width = 0.0;  ///< Rear track width
  double center_of_gravity_height = 0.208; ///< Height of the center of gravity
  double mass = 0.0; ///< Vehicle mass
  double moment_of_inertia_z = 0.0; ///< Yaw moment of inertia
  double wheel_radius = 0.0; ///< Wheel radius
  double gear_ratio = 0.0; ///< Drivetrain gear ratio
  double inner_steering_ratio = 0.0; ///< Inner wheel steering ratio
  double outer_steering_ratio = 0.0; ///< Outer wheel steering ratio
  double cornering_stiffness_front = 0.0; ///< Front cornering stiffness
  double cornering_stiffness_rear = 0.0; ///< Rear cornering stiffness
  double max_lateral_acceleration = 0.0; ///< Maximum lateral acceleration

  double max_drive_torque = 0.0; ///< Maximum drive torque
  double max_brake_torque = 0.0; ///< Maximum brake torque
  double max_yaw_moment = 0.0; ///< Maximum yaw moment

  /**
   * @brief Tire model parameters
   * 
   */
  struct TireParameters {
    double lateral_stiffness_factor = 0.0; ///< Lateral stiffness factor
    double shape_factor = 0.0; ///< Shape factor
    double peak_factor = 0.0; ///< Peak factor
    double curvature_factor = 0.0; ///< Curvature factor
  } tire_parameters; ///< Tire model parameters

  /**
   * @brief Aerodynamics parameters
   * 
   */
  struct AerodynamicsParameters { 
    double drag_coefficient = 0.0; ///< Drag coefficient
    double frontal_area = 0.0; ///< Frontal area
    double lift_coefficient = 0.0; ///< Lift coefficient
    double center_of_pressure_distribution = 0.0; ///< Center of pressure distribution
  } aerodynamics_parameters; ///< Aerodynamics parameters
};