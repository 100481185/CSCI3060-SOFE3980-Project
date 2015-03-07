cmake_minimum_required(VERSION 2.8.4)
project(xstream)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(xstream/include)

include_directories(xstream/data)

set(CMAKE_BINARY_DIR ../xstream/build)

set(EXECUTABLE_OUTPUT_PATH xstream/bin)

set(CMAKE_SOURCE_DIR xstream/src)

set(SOURCE_FILES ../main.cpp
                 xstream/src/xstream.cpp
                 xstream/src/session.cpp
                 xstream/src/data.cpp
                 xstream/src/transaction.cpp
                 xstream/src/accounts.cpp
                 xstream/src/user.cpp
                 xstream/src/commit.cpp
                 xstream/data/UserAccounts.txt
                 xstream/data/DailyTransactions.txt
)

add_executable(xstream ${SOURCE_FILES})

