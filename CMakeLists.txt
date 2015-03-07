cmake_minimum_required(VERSION 2.8.4)
project(XSTREAM)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_subdirectory(xstream)

file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)
configure_file(xstream/data/UserAccounts.txt ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)
configure_file(xstream/data/DailyTransactions.txt ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)
configure_file(xstream/data/AvailableTickets.txt ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data)


