#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "reference_generators/reference_generator.hpp"

using ::testing::_;
using ::testing::Return;

class MockYawRateReferenceGenerator : public YawRateReferenceGenerator {
public:
    MOCK_METHOD(double, generate_reference_yaw_rate,
                (VehicleState state, DriverCommand command), (override));
};


class MockSideslipReferenceGenerator : public SideslipReferenceGenerator {
public:
    MOCK_METHOD(double, generate_reference_sideslip,
                (VehicleState state, DriverCommand command, double reference_yaw_rate), (override));
};

class ReferenceGeneratorTest : public ::testing::Test {
protected:
    MockYawRateReferenceGenerator yaw_rate_gen;
    MockSideslipReferenceGenerator sideslip_gen;

    ReferenceGenerator* ref_gen;

    VehicleState state;
    DriverCommand command;

    void SetUp() override {
        ref_gen = new ReferenceGenerator(&yaw_rate_gen, &sideslip_gen);
    }

    void TearDown() override {
        delete ref_gen;
    }
};

TEST_F(ReferenceGeneratorTest, CreatesReferenceWithExpectedValues) {
    const double expected_yaw_rate = 0.25;
    const double expected_sideslip = 0.05;

    EXPECT_CALL(yaw_rate_gen, generate_reference_yaw_rate(_, _))
        .WillOnce(Return(expected_yaw_rate));

    EXPECT_CALL(sideslip_gen, generate_reference_sideslip(_, _, expected_yaw_rate))
        .WillOnce(Return(expected_sideslip));

    Reference ref = ref_gen->create_reference(state, command);

    EXPECT_DOUBLE_EQ(ref.yaw_rate, expected_yaw_rate);
    EXPECT_DOUBLE_EQ(ref.sideslip_angle, expected_sideslip);
}