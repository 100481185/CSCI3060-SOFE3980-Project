#ifndef XSTREAM_SESSION_H
#define XSTREAM_SESSION_H

#include "../include/user.h"
#include "../include/accounts.h"
#include "../include/transaction.h"

/*
Session:
    Provides users with access to session controls. Handles
    the creation and control of memory elements. Provides
    users with access to data elements.
 */
class Session
{
public:
    /*
    Constructor:
        sets logged_in_ to NULL and creates the new
        Transactions memory
     */
    Session();

    /*
    logged_in:
        Return false if logged_in_ points to NULL
     */
    bool logged_in() const;

    /*
    Login:
        enables a user to login to a session. Prompts
        user for username.
        Return 0 on success, -1 on invalid input,
               -2 on invalid username
     */
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
