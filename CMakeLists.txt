cmake_minimum_required(VERSION 2.8.4)
project(XSTREAM)

set(EXECUTABLE_OUTPUT_PATH build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/data)
configure_file(xstream/data/UserAccounts.txt ${PROJECT_BINARY_DIR}/data)
configure_file(xstream/data/DailyTransactions.txt ${PROJECT_BINARY_DIR}/data)
configure_file(xstream/data/AvailableTickets.txt ${PROJECT_BINARY_DIR}/data)


set(SOURCE_FILES xstream/src/main.cpp
                 xstream/src/session.cpp
                 xstream/src/data.cpp
                 xstream/src/transaction.cpp
                 xstream/src/accounts.cpp
                 xstream/src/user.cpp
                 xstream/src/commit.cpp
		         xstream/src/tickets.cpp
		         xstream/src/event.cpp
                 xstream/data/UserAccounts.txt
                 xstream/data/DailyTransactions.txt
		         xstream/data/AvailableTickets.txt
)

add_executable(xstream ${SOURCE_FILES})

install(TARGETS xstream DESTINATION build)