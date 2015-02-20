cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(gtest REQUIRED)
include_directories(gtest)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests sample1.cpp ../control.cpp)
target_link_libraries(runTests gtest pthread)