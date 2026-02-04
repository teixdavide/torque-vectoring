#include <gtest/gtest.h>

#include "high_level_controllers/pid_controller.hpp"

class PIDControllerTest : public ::testing::Test {
protected:
    CarParameters car_params = {
        .mass = 269.6,
        .front_axle_distance = 1.20,
        .rear_axle_distance = 1.20,
        .cornering_stiffness_front = 127,
        .cornering_stiffness_rear = 127,
        .max_lateral_acceleration = 1.48 * 9.81,
        .max_yaw_moment = 150.0,
        .max_drive_torque = 400.0,
        .max_brake_torque = 300.0
    };

    VehicleState state{};
    Reference reference{};
    DriverCommand command{};

    const double kp = 2.0;
    const double ki = 1.0;
    const double kd = 0.5;
    const double dt = 0.01;
    const double integral_limit = 5.0;
};

/**
 * @brief Test: Zero error produces zero yaw moment
 */
TEST_F(PIDControllerTest, ZeroErrorProducesZeroYawMoment) {
    PIDController controller(car_params, kp, ki, kd, dt, integral_limit);

    state.yaw_rate = 0.5;
    reference.yaw_rate = 0.5;
    command.throttle = 0.0;

    auto request = controller.compute_control(state, reference, command);

    EXPECT_DOUBLE_EQ(request.yaw_moment, 0.0);
}

/**
 * @brief Test: Proportional term contributes correctly
 */
TEST_F(PIDControllerTest, ProportionalControlContribution) {
    PIDController controller(car_params, kp, 0.0, 0.0, dt, integral_limit);

    state.yaw_rate = 0.2;
    reference.yaw_rate = 1.0;

    auto request = controller.compute_control(state, reference, command);

    double error = reference.yaw_rate - state.yaw_rate;
    double expected_yaw_moment = kp * error;

    EXPECT_NEAR(request.yaw_moment, expected_yaw_moment, 1e-6);
}

/**
 * @brief Test: Integral term accumulates over time
 */
TEST_F(PIDControllerTest, IntegralTermAccumulates) {
    PIDController controller(car_params, 0.0, ki, 0.0, dt, integral_limit);

    state.yaw_rate = 0.0;
    reference.yaw_rate = 1.0;

    double expected_integral = 0.0;

    for (int i = 0; i < 10; ++i) {
        expected_integral += (reference.yaw_rate - state.yaw_rate) * dt;
        auto request = controller.compute_control(state, reference, command);

        EXPECT_NEAR(request.yaw_moment, ki * expected_integral, 1e-6);
    }
}

/**
 * @brief Test: Integral term is clamped by integral limit
 */
TEST_F(PIDControllerTest, IntegralAntiWindupClampsCorrectly) {
    PIDController controller(car_params, 0.0, ki, 0.0, dt, integral_limit);

    state.yaw_rate = 0.0;
    reference.yaw_rate = 10.0;

    for (int i = 0; i < 100; ++i) {
        controller.compute_control(state, reference, command);
    }

    auto request = controller.compute_control(state, reference, command);

    EXPECT_NEAR(request.yaw_moment, ki * integral_limit, 1e-6);
}

/**
 * @brief Test: Derivative term responds to changing error
 */
TEST_F(PIDControllerTest, DerivativeTermRespondsToErrorChange) {
    PIDController controller(car_params, 0.0, 0.0, kd, dt, integral_limit);

    state.yaw_rate = 0.0;
    reference.yaw_rate = 0.0;

    controller.compute_control(state, reference, command);

    reference.yaw_rate = 1.0;
    auto request = controller.compute_control(state, reference, command);

    double expected_derivative =
        (reference.yaw_rate - state.yaw_rate) / dt;

    EXPECT_NEAR(request.yaw_moment, kd * expected_derivative, 1e-6);
}