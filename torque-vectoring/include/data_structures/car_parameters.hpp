#pragma once

struct CarParameters {
  double front_axle_distance;
  double rear_axle_distance;
  double front_track_width;
  double rear_track_width;
  double center_of_gravity_height;
  double mass;
  double moment_of_inertia_z;
  double wheel_radius;
  double gear_ratio;
  double inner_steering_ratio;
  double outer_steering_ratio;
  double cornering_stiffness_front;
  double cornering_stiffness_rear;
  double max_lateral_acceleration;

  double max_drive_torque;
  double max_brake_torque;
  double max_yaw_moment;

  struct TireParameters {
    double lateral_stiffness_factor;
    double shape_factor;
    double peak_factor;
    double curvature_factor;
  } tire_parameters;

  struct AerodynamicsParameters {
    double drag_coefficient;
    double frontal_area;
    double lift_coefficient;
    double center_of_pressure_distribution;
  } aerodynamics_parameters;
};