cmake_minimum_required(VERSION 2.8.4)
project(runTests)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


find_package(GTest REQUIRED)
include_directories("${PROJECT_BINARY_DIR} ${GTEST_INCLUDE_DIRS}")

set(SOURCE_FILES
                 #xstream/src/main.cpp
                 xstream/src/xstream.h
                 xstream/src/controller/control.cpp
                 xstream/src/controller/control.h
                 xstream/src/login/login.cpp
                 xstream/src/login/login.h
                 xstream/src/logout/logout.cpp
                 xstream/src/logout/logout.h
                 xstream/src/data/session.cpp
                 xstream/src/data/session.h
                 xstream/src/data/user/account.cpp
                 xstream/src/data/user/account.h
                 xstream/src/data/daily/transaction.cpp
                 xstream/src/data/daily/transaction.h
                 xstream/src/data/available/tickets.cpp
                 xstream/src/data/available/tickets.h
                 xstream/test/ControlTestSuite.h
                 xstream/test/LoginTestSuite.h
                 xstream/test/main.cpp
                 )

add_executable(runTests ${SOURCE_FILES})

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)