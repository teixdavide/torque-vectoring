cmake_minimum_required(VERSION 3.16)

project(torque_vectoring
    VERSION 1.0.0
    DESCRIPTION "Torque Vectoring Library with Tests"
    LANGUAGES CXX
)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -------------------------------
# 1️⃣ Create the library
# -------------------------------
add_library(torque_vectoring
    src/reference_generators/reference_generator.cpp
    src/reference_generators/sideslip_reference_generators/steady_state_sideslip_reference_generator.cpp
    src/reference_generators/yaw_rate_reference_generators/steady_state_yaw_rate_reference_generator.cpp
)

# Include directories
target_include_directories(torque_vectoring
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Compiler warnings
target_compile_options(torque_vectoring
    PRIVATE -Wall -Wextra -Wpedantic
)

target_compile_definitions(torque_vectoring
    PRIVATE TORQUE_VECTORING_BUILD
)

# -------------------------------
# 2️⃣ Add GoogleTest for unit tests
# -------------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# -------------------------------
# 3️⃣ Test executable
# -------------------------------
add_executable(reference_generator_tests
    test/reference_generators/ref_gen_test.cpp
)

# Link library and GoogleTest/GoogleMock
target_link_libraries(reference_generator_tests
    PRIVATE
        torque_vectoring
        gtest_main
        gmock
)

# Include library headers
target_include_directories(reference_generator_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}/include   # <-- ensure gtest/gmock headers are visible
        ${gmock_SOURCE_DIR}/include
)


# Compiler warnings for tests
target_compile_options(reference_generator_tests
    PRIVATE -Wall -Wextra -Wpedantic
)

# Register tests with CTest
include(GoogleTest)
gtest_discover_tests(reference_generator_tests)
