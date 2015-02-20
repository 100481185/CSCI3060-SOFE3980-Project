cmake_minimum_required(VERSION 2.8.4)
project(runTests)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


find_package(GTest REQUIRED)
include_directories("${PROJECT_BINARY_DIR} ${GTEST_INCLUDE_DIRS}")

set(SOURCE_FILES xstream/src/control.cpp
                 xstream/src/login.cpp
                 xstream/src/account.cpp
                 xstream/src/account.cpp
                 xstream/src/test/ControlTestSuite.h
                 xstream/src/test/main.cpp )

add_executable(runTests ${SOURCE_FILES})

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)