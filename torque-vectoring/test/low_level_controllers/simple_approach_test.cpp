#include <gtest/gtest.h>
#include "low_level_controllers/simple_approach.hpp"

/**
 * @brief Test fixture for the SimpleApproach torque allocator.
 *
 * This fixture initializes consistent vehicle parameters used across all tests.
 * The SimpleApproach controller distributes total rear torque and yaw moment
 * into individual rear wheel torques.
 */
class SimpleApproachTest : public ::testing::Test {
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
};

/**
 * @brief Test: Zero yaw moment produces equal torque distribution on rear wheels.
 *
 * If no yaw moment is requested, the controller should split total torque
 * evenly between left and right rear wheels.
 *
 * This verifies:
 *  - No unintended bias
 *  - Correct base torque split (T/2, T/2)
 *  - Front wheels receive zero torque
 */
TEST_F(SimpleApproachTest, ZeroYawMomentProducesEqualRearSplit) {
    SimpleApproach controller(car_params);

    YawMomentTorqueRequest request{};
    request.yaw_moment = 0.0;
    request.total_torque = 100.0;

    auto output = controller.compute_control(request);

    EXPECT_DOUBLE_EQ(output.fl_torque, 0.0);
    EXPECT_DOUBLE_EQ(output.fr_torque, 0.0);
    EXPECT_DOUBLE_EQ(output.rl_torque, 50.0);
    EXPECT_DOUBLE_EQ(output.rr_torque, 50.0);
}

/**
 * @brief Test: Positive yaw moment increases left rear torque.
 *
 * According to the implementation:
 *     delta = yaw_moment / rear_axle_distance
 *
 * RL = T/2 + delta
 * RR = T/2 - delta
 *
 * This test verifies:
 *  - Correct computation of delta torque
 *  - Proper directional torque adjustment
 */
TEST_F(SimpleApproachTest, PositiveYawMomentAddsToLeftRear) {
    SimpleApproach controller(car_params);

    YawMomentTorqueRequest request{};
    request.yaw_moment = 12.0;
    request.total_torque = 100.0;

    auto output = controller.compute_control(request);

    double delta = request.yaw_moment / car_params.rear_axle_distance;

    EXPECT_DOUBLE_EQ(output.rl_torque, 50.0 + delta);
    EXPECT_DOUBLE_EQ(output.rr_torque, 50.0 - delta);
}

/**
 * @brief Test: Negative yaw moment increases right rear torque.
 *
 * Ensures sign correctness in yaw moment handling.
 * A negative yaw moment must invert the torque bias.
 *
 * This verifies:
 *  - Correct sign propagation
 *  - No accidental inversion in formula
 */
TEST_F(SimpleApproachTest, NegativeYawMomentAddsToRightRear) {
    SimpleApproach controller(car_params);

    YawMomentTorqueRequest request{};
    request.yaw_moment = -12.0;
    request.total_torque = 100.0;

    auto output = controller.compute_control(request);

    double delta = request.yaw_moment / car_params.rear_axle_distance;

    EXPECT_DOUBLE_EQ(output.rl_torque, 50.0 + delta);
    EXPECT_DOUBLE_EQ(output.rr_torque, 50.0 - delta);
}

/**
 * @brief Test: Rear torque sum equals total requested torque.
 *
 * Since:
 *     RL = T/2 + delta
 *     RR = T/2 - delta
 *
 * Their sum must always equal T.
 *
 * This verifies:
 *  - No torque is artificially created or destroyed
 *  - Mathematical consistency of the allocator
 */
TEST_F(SimpleApproachTest, TotalRearTorqueIsConserved) {
    SimpleApproach controller(car_params);

    YawMomentTorqueRequest request{};
    request.yaw_moment = 20.0;
    request.total_torque = 100.0;

    auto output = controller.compute_control(request);

    double rear_sum = output.rl_torque + output.rr_torque;

    EXPECT_DOUBLE_EQ(rear_sum, request.total_torque);
}

/**
 * @brief Test: Pure yaw moment generation with zero total torque.
 *
 * If total torque is zero but yaw moment is nonzero:
 *
 *     RL = +delta
 *     RR = -delta
 *
 * This produces a pure moment without longitudinal acceleration.
 *
 * This verifies:
 *  - Correct handling of edge case
 *  - Controller supports moment-only actuation
 */
TEST_F(SimpleApproachTest, ZeroTotalTorqueStillProducesYawSplit) {
    SimpleApproach controller(car_params);

    YawMomentTorqueRequest request{};
    request.yaw_moment = 12.0;
    request.total_torque = 0.0;

    auto output = controller.compute_control(request);

    double delta = request.yaw_moment / car_params.rear_axle_distance;

    EXPECT_DOUBLE_EQ(output.rl_torque, delta);
    EXPECT_DOUBLE_EQ(output.rr_torque, -delta);
}

