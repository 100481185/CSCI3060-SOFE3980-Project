#ifndef XSTREAM_SESSION_H
#define XSTREAM_SESSION_H

#include "../include/user.h"
#include "../include/accounts.h"
#include "../include/transaction.h"


class Session
{
public:
    Session();

    bool logged_in() const;

    int Login();

    int Logout();

    int Create();

    int Delete();

    int Sell();

    int Buy();

    int Refund();

    int AddCredit();

private:
    User *logged_in_;
    Accounts *accounts_;
    Transactions *transactions_;
//    Tickets * tickets;
};

#endif // XSTREAM_SESSION_H
