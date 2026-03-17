#include <gtest/gtest.h>

#include "reference_generators/sideslip_reference_generators/steady_state_sideslip_reference_generator.hpp"
#include "data_structures/vehicle_state.hpp"
#include "data_structures/driver_command.hpp"
#include "data_structures/car_parameters.hpp"

class SteadyStateSideslipReferenceGeneratorTest : public ::testing::Test {
protected:

    CarParameters car_params{};
    VehicleState state{};
    DriverCommand command{};

    void SetUp() override
    {
        car_params.mass = 269.6;
        car_params.front_axle_distance = 1.20;
        car_params.rear_axle_distance = 1.20;
        car_params.cornering_stiffness_front = 127;
        car_params.cornering_stiffness_rear = 127;
        car_params.max_lateral_acceleration = 1.48 * 9.81;
        car_params.max_yaw_moment = 150.0;
        car_params.max_drive_torque = 400.0;
        car_params.max_brake_torque = 300.0;
    }
};

/**
 * @brief Test: Sideslip is zero if velocity < 0.1 m/s
 */
TEST_F(SteadyStateSideslipReferenceGeneratorTest, ReturnsZeroWhenVelocityLow) {
    SteadyStateSideslipReferenceGenerator generator(car_params);

    state.velocity_x = 0.05;
    double reference_yaw_rate = 0.3;

    double beta = generator.generate_reference_sideslip(state, command, reference_yaw_rate);

    EXPECT_DOUBLE_EQ(beta, 0.0);
}

/**
 * @brief Test: Normal steady-state sideslip computation
 */
TEST_F(SteadyStateSideslipReferenceGeneratorTest, ComputesSideslipCorrectly) {
    SteadyStateSideslipReferenceGenerator generator(car_params);

    state.velocity_x = 10.0;
    double reference_yaw_rate = 0.2;

    double beta = generator.generate_reference_sideslip(state, command, reference_yaw_rate);

    double lr = car_params.rear_axle_distance;
    double lf = car_params.front_axle_distance;
    double L  = lf + lr;
    double V  = state.velocity_x;
    double m  = car_params.mass;
    double Cr = car_params.cornering_stiffness_rear;

    double expected_beta =
        (lr / V - (m * lf * V) / (L * Cr)) * reference_yaw_rate;

    EXPECT_NEAR(beta, expected_beta, 1e-6);
}

/**
 * @brief Test: Zero yaw rate yields zero sideslip
 */
TEST_F(SteadyStateSideslipReferenceGeneratorTest, ZeroYawRateReturnsZeroSideslip) {
    SteadyStateSideslipReferenceGenerator generator(car_params);

    state.velocity_x = 10.0;
    double reference_yaw_rate = 0.0;

    double beta = generator.generate_reference_sideslip(state, command, reference_yaw_rate);

    EXPECT_DOUBLE_EQ(beta, 0.0);
}