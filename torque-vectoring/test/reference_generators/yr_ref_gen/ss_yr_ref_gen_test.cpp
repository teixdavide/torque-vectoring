#include <gtest/gtest.h>

#include "reference_generators/yaw_rate_reference_generators/steady_state_yaw_rate_reference_generator.hpp"
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/car_parameters.hpp"

class SteadyStateYawRateReferenceGeneratorTest : public ::testing::Test {
protected:
    // Updated car parameters
    CarParameters car_params = {
        .mass = 269.6,                     // kg
        .front_axle_distance = 1.20,       // m
        .rear_axle_distance = 1.20,        // m
        .cornering_stiffness_front = 127,  // N/rad
        .cornering_stiffness_rear = 127,   // N/rad
        .max_lateral_acceleration = 1.48 * 9.81 // m/s^2
    };

    VehicleState state{};
    DriverCommand command{};
};

/**
 * @brief Test: Yaw rate is zero if velocity < 0.1 m/s
 * 
 */
TEST_F(SteadyStateYawRateReferenceGeneratorTest, ReturnsZeroWhenVelocityLow) {
    SteadyStateYawRateReferenceGenerator generator(car_params);

    state.velocity_x = 0.05;
    command.steering = 0.1;

    double yaw_rate = generator.generate_reference_yaw_rate(state, command);

    EXPECT_DOUBLE_EQ(yaw_rate, 0.0);
}

/**
 * @brief Test: Normal yaw rate computation
 * 
 */
TEST_F(SteadyStateYawRateReferenceGeneratorTest, ComputesYawRate) {
    SteadyStateYawRateReferenceGenerator generator(car_params);

    state.velocity_x = 10.0;
    command.steering = 0.1;

    double yaw_rate = generator.generate_reference_yaw_rate(state, command);

    double L = car_params.front_axle_distance + car_params.rear_axle_distance;
    double lf = car_params.front_axle_distance;
    double lr = car_params.rear_axle_distance;
    double Cf = car_params.cornering_stiffness_front;
    double Cr = car_params.cornering_stiffness_rear;
    double m = car_params.mass;

    double k = m / (lr + lf) * (lr / Cf - lf / Cr);
    double expected_yaw_rate = state.velocity_x / (L * (1 + k * state.velocity_x * state.velocity_x)) * command.steering;

    EXPECT_NEAR(yaw_rate, expected_yaw_rate, 1e-6);
}

/**
 * @brief Test: Increasing velocity increases yaw rate for constant steering
 * 
 */
TEST_F(SteadyStateYawRateReferenceGeneratorTest, CheckIncreasingVelocityIncreasesYawRate) {
     SteadyStateYawRateReferenceGenerator generator(car_params);

    command.steering = 0.1;
    double previous_yaw_rate = 0.0;

    for (double vel = 5.0; vel <= 14.0; vel += 1.0) {
        state.velocity_x = vel;
        double yaw_rate = generator.generate_reference_yaw_rate(state, command);    
        EXPECT_LE(previous_yaw_rate, yaw_rate);
        previous_yaw_rate = yaw_rate;
    }
}

TEST_F(SteadyStateYawRateReferenceGeneratorTest, CheckIncreasingSteeringIncreasesYawRate) {
     SteadyStateYawRateReferenceGenerator generator(car_params);

    state.velocity_x = 10.0;
    double previous_yaw_rate = 0.0;

    for (double steer = 0.05; steer <= 0.5; steer += 0.05) {
        command.steering = steer;
        double yaw_rate = generator.generate_reference_yaw_rate(state, command);    
        EXPECT_LE(previous_yaw_rate, yaw_rate);
        previous_yaw_rate = yaw_rate;
    }
}

/**
 * @brief Test: Yaw rate limited by max lateral acceleration
 * 
 */
TEST_F(SteadyStateYawRateReferenceGeneratorTest, YawRateLimitedByMaxLateralAcceleration) {
    SteadyStateYawRateReferenceGenerator generator(car_params);

    state.velocity_x = 5.0;
    command.steering = 30.0;

    double yaw_rate = generator.generate_reference_yaw_rate(state, command);

    double yaw_rate_limit = car_params.max_lateral_acceleration / state.velocity_x;

    EXPECT_LE(yaw_rate, yaw_rate_limit + 1e-6);
    EXPECT_GE(yaw_rate, -yaw_rate_limit - 1e-6);
}

/**
 * @brief Test: Override understeer coefficient
 * 
 */
TEST_F(SteadyStateYawRateReferenceGeneratorTest, OverrideUndersteerCoefficient) {
    double custom_k = 0.5;
    SteadyStateYawRateReferenceGenerator generator(car_params, true, custom_k);

    state.velocity_x = 8.0;
    command.steering = 0.2;

    double yaw_rate = generator.generate_reference_yaw_rate(state, command);

    double L = car_params.front_axle_distance + car_params.rear_axle_distance;
    double expected_yaw_rate = state.velocity_x / (L * (1 + custom_k * state.velocity_x * state.velocity_x)) * command.steering;

    EXPECT_NEAR(yaw_rate, expected_yaw_rate, 1e-6);
}
