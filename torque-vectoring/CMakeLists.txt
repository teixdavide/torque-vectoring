cmake_minimum_required(VERSION 3.16)

project(torque_vectoring
    VERSION 1.0.0
    DESCRIPTION "Torque Vectoring Library with Tests"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(torque_vectoring
    src/reference_generators/reference_generator.cpp
    src/reference_generators/sideslip_reference_generators/steady_state_sideslip_reference_generator.cpp
    src/reference_generators/yaw_rate_reference_generators/steady_state_yaw_rate_reference_generator.cpp
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

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Enabling code coverage flags")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()


add_executable(reference_generator_tests
    test/reference_generators/ref_gen_test.cpp
    test/reference_generators/yr_ref_gen/ss_yr_ref_gen_test.cpp
)

target_link_libraries(reference_generator_tests
    PRIVATE
        torque_vectoring
        gtest_main
        gmock
)

target_include_directories(reference_generator_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}/include
        ${gmock_SOURCE_DIR}/include
)


target_compile_options(reference_generator_tests
    PRIVATE -Wall -Wextra -Wpedantic
)

include(GoogleTest)

gtest_discover_tests(reference_generator_tests
    TIMEOUT 0   # disables timeout
)

gtest_discover_tests(reference_generator_tests)
