cmake_minimum_required(VERSION 2.8.4)
project(XSTREAM)

set(EXECUTABLE_OUTPUT_PATH build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/data)
configure_file(data/UserAccounts.txt ${PROJECT_BINARY_DIR}/data)
configure_file(data/DailyTransactions.txt ${PROJECT_BINARY_DIR}/data)
configure_file(data/AvailableTickets.txt ${PROJECT_BINARY_DIR}/data)


set(SOURCE_FILES src/main.cpp
                 src/session.cpp
                 src/data.cpp
                 src/transaction.cpp
                 src/accounts.cpp
                 src/user.cpp
                 src/commit.cpp
		         src/tickets.cpp
		         src/event.cpp
                 data/UserAccounts.txt
                 data/DailyTransactions.txt
		         data/AvailableTickets.txt
)

add_executable(xstream ${SOURCE_FILES})

install(TARGETS xstream DESTINATION build)