#set(CMAKE_CURRENT_BINARY_DIR)
#set(EXECUTABLE_OUTPUT_PATH )

file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/xstream/data)

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

configure_file(data/UserAccounts.txt ${XSTREAM_BINARY_DIR}/xstream/data)
configure_file(data/DailyTransactions.txt ${XSTREAM_BINARY_DIR}/xstream/data)
configure_file(data/AvailableTickets.txt ${XSTREAM_BINARY_DIR}/xstream/data)