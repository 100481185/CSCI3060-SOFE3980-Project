cmake_minimum_required(VERSION 2.8.4)
project(XSTREAM)



if(${PROJECT_BINARY_DIR} MATCHES "/home/nicholas/.clion10/system/cmake/generated")
    file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/build)
    file(MAKE_DIRECTORY ${PROJECT_SOURCE_DIR}/build/data)
    configure_file(data/UserAccounts.txt ${PROJECT_SOURCE_DIR}/build/data)
    configure_file(data/DailyTransactions.txt ${PROJECT_SOURCE_DIR}/build/data)
    configure_file(data/AvailableTickets.txt ${PROJECT_SOURCE_DIR}/build/data)
else(${PROJECT_BINARY_DIR} MATCHES "/home/nicholas/.clion10/system/cmake/generated")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
    file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/data)
    configure_file(data/UserAccounts.txt ${PROJECT_BINARY_DIR}/data)
    configure_file(data/DailyTransactions.txt ${PROJECT_BINARY_DIR}/data)
    configure_file(data/AvailableTickets.txt ${PROJECT_BINARY_DIR}/data)
endif(${PROJECT_BINARY_DIR} MATCHES "/home/nicholas/.clion10/system/cmake/generated")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(EXECUTABLE_OUTPUT_PATH build)


set(SOURCE_FILES src/main.cpp
                 src/session.cpp
                 include/session.h
                 src/data.cpp
                 include/data.h
                 src/transaction.cpp
                 include/transaction.h
                 src/accounts.cpp
                 include/accounts.h
                 src/user.cpp
                 include/user.h
                 src/commit.cpp
                 include/commit.h
		         src/tickets.cpp
		         include/tickets.h
		         src/event.cpp
		         include/event.h
                 data/UserAccounts.txt
                 data/DailyTransactions.txt
		         data/AvailableTickets.txt
)

add_executable(xstream ${SOURCE_FILES})

install(TARGETS xstream DESTINATION build)