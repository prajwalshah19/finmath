cmake_minimum_required(VERSION 3.10)

project(finmath)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add debugging symbols
set(CMAKE_BUILD_TYPE Debug)

# Add include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
file(GLOB SOURCES "src/cpp/*/*.cpp")

# Create the library
add_library(finmath SHARED ${SOURCES}
        "src/cpp/Interest and Annuities/simple_interest.cpp"
        "include/finmath/Interest and Annuities/simple_interest.h"
        "include/finmath/Option Pricing/options_pricing.h"
        "include/finmath/Option Pricing/options_pricing_types.h")

# Test executable
add_executable(runTests test/test_finmath.cpp)
target_link_libraries(runTests finmath)

# Enable testing
enable_testing()

# Define tests
add_test(NAME UnitTests COMMAND runTests)

# Ensure 'make' builds the tests and then runs them
add_custom_target(build_and_test
    COMMAND ${CMAKE_COMMAND} --build . --target runTests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Make 'build_and_test' the default target
add_custom_target(default ALL DEPENDS build_and_test)

# Add pybind11 for Python bindings
include(FetchContent)
FetchContent_Declare(
    pybind11
    GIT_REPOSITORY https://github.com/pybind/pybind11.git
    GIT_TAG v2.10.0  # Use a stable version of pybind11
)
FetchContent_MakeAvailable(pybind11)

# Create the Python bindings target
pybind11_add_module(finmath_bindings src/python_bindings.cpp ${SOURCES})
