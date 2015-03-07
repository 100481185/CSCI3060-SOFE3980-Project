

message(STATUS ${PROJECT_BIN_DIR})


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
