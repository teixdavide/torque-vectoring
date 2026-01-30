cmake_minimum_required(VERSION 3.16)

project(torque_vectoring
    VERSION 1.0.0
    DESCRIPTION "Torque Vectoring Library"
    LANGUAGES CXX
)

# Use modern C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create the library
add_library(torque_vectoring
    src/reference_generators/reference_generator.cpp
    src/reference_generators/sideslip_reference_generators/steady_state_sideslip_reference_generator.cpp
    src/reference_generators/yaw_rate_reference_generators/steady_state_yaw_rate_reference_generator.cpp
)

# Public include directory
target_include_directories(torque_vectoring
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Compiler warnings (optional but recommended)
target_compile_options(torque_vectoring
    PRIVATE
        -Wall -Wextra -Wpedantic
)

# Optional: define export macro for shared libs
target_compile_definitions(torque_vectoring
    PRIVATE TORQUE_VECTORING_BUILD
)
