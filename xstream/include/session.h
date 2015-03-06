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
        RETURN false if logged_in_ points to NULL
     */
    bool logged_in() const;

    int command(string cmd);



private:
    User *logged_in_;
    Accounts *accounts_;
    Transactions *transactions_;
    Tickets * tickets_;

    /*
    Login:
        enables a user to login to a session. Prompts
        user for username.
        RETURN 0 on success, -1 on invalid input,
               -2 on invalid username
     */
    int Login();

    /*
    Logout:
        logs the current user out of the session and writes
        all transactions, account changes and ticket changes to
        their respective files
        RETURN 0 on success or -int for error
     */
    int Logout();

    /*
    Create:
        enables admin users to create a new user. The method
        creates a new account in memory and then writes the new
        user to UserAccounts file
        RETURN 0 on success or -int for error
     */
    int Create();

    /*
    Delete:
        enables admin users to delete a user account. The method
        deletes the account in memory and then writes the deleted
        account to the UserAccounts file
        RETURN 0 on success or -int for error
     */
    int Delete();

    /*
    Sell:
        enables users with sell privileges and are logged to sell
        tickets to an event. the method creates post tickets to an event for sale.
        RETURN 0 on success or -int for error
     */
    int Sell();

    /*
    Buy:
        enables a u
     */
    int Buy();

    int Refund();

    int AddCredit();
};

#endif // XSTREAM_SESSION_H
