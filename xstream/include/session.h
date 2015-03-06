#ifndef XSTREAM_SESSION_H
#define XSTREAM_SESSION_H

#include "../include/user.h"
#include "../include/accounts.h"
#include "../include/tickets.h"
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

    /*
    Logout:
        logs the current user out of the session and writes
        all transactions, account changes and ticket changes to
        their respective files
     */
    int Logout();

    /*
    Create:
        enables admin users to create a new user. The method
        creates a new account in memory and then writes the new
        user to UserAccounts file
     */
    int Create();

    /*
    Delete:
        enables admin users to delete a user account. The method
        deletes the account in memory and then writes the deleted
        account to the UserAccounts file
     */
    int Delete();

    int Sell();

    int Buy();

    int Refund();

    int AddCredit();

private:
    User *logged_in_;
    Accounts *accounts_;
    Transactions *transactions_;
    Tickets * tickets_;
};

#endif // XSTREAM_SESSION_H
