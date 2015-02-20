cmake_minimum_required(VERSION 2.8.4)
project(QandA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/login.cpp src/cmdfilter.cpp src/account.cpp)
add_executable(QandA ${SOURCE_FILES})