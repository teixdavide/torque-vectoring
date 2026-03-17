cmake_minimum_required(VERSION 3.16)

project(torque_vectoring
    VERSION 1.0.0
    DESCRIPTION "Torque Vectoring Library with Tests and ROS2 Node"
    LANGUAGES CXX
)

# -------------------------
# C++ Settings
# -------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------
# ROS2 Dependencies
# -------------------------
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# -------------------------
# Library
# -------------------------
add_library(torque_vectoring
    src/reference_generators/reference_generator.cpp
    src/reference_generators/sideslip_reference_generators/steady_state_sideslip_reference_generator.cpp
    src/reference_generators/yaw_rate_reference_generators/steady_state_yaw_rate_reference_generator.cpp
    src/high_level_controllers/pid_controller.cpp
    src/low_level_controllers/simple_approach.cpp
    src/torque_vectoring.cpp
)

target_include_directories(torque_vectoring
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(torque_vectoring
    PRIVATE -Wall -Wextra -Wpedantic
)

target_compile_definitions(torque_vectoring
    PRIVATE TORQUE_VECTORING_BUILD
)

ament_target_dependencies(torque_vectoring
    rclcpp
    std_msgs
    geometry_msgs
)

# -------------------------
# ROS2 Node
# -------------------------
add_executable(torque_vectoring_node
    src/torque_vectoring_node.cpp
)

target_link_libraries(torque_vectoring_node
    torque_vectoring
)

ament_target_dependencies(torque_vectoring_node
    rclcpp
    std_msgs
)

# -------------------------
# Testing Setup
# -------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Code coverage (Debug builds)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Enabling code coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# -------------------------
# Test Executable
# -------------------------
#add_executable(tv_tests
    #test/reference_generators/ref_gen_test.cpp
    #test/reference_generators/yr_ref_gen/ss_yr_ref_gen_test.cpp
    #test/reference_generators/ss_ss_ref_gen/ss_ss_ref_gen_test.cpp
    #test/high_level_controllers/pid_controller_test.cpp
    #test/low_level_controllers/simple_approach_test.cpp
#)

#target_link_libraries(tv_tests
#    PRIVATE
#        torque_vectoring
#        gtest_main
#        gmock
#)

#target_include_directories(tv_tests
#    PRIVATE
#        ${CMAKE_CURRENT_SOURCE_DIR}/include
#        ${gtest_SOURCE_DIR}/include
#        ${gmock_SOURCE_DIR}/include
#)

#target_compile_options(tv_tests
#    PRIVATE -Wall -Wextra -Wpedantic
#)

include(GoogleTest)

#gtest_discover_tests(tv_tests
#    TIMEOUT 0
#)

# -------------------------
# Install Targets
# -------------------------
install(
    TARGETS
        torque_vectoring
        torque_vectoring_node
    DESTINATION lib/${PROJECT_NAME}
)

install(
    DIRECTORY include/
    DESTINATION include
)

# -------------------------
# Export Package
# -------------------------
ament_export_include_directories(include)
ament_export_libraries(torque_vectoring)
ament_package()