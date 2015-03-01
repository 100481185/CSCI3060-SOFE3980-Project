#ifndef XSTREAM_USER_ACCOUNTS_H
#define XSTREAM_USER_ACCOUNTS_H

#include "../include/data.h"
#include "user.h"
#include <iostream>
#include <string>
#include <map>

// path to the UserAccount.txt file
#define USER_ACCOUNTS "data/UserAccounts.txt"
// User Type Constants
#define AA "admin"
#define FS "full-standard"
#define BS "buy-standard"
#define SS "sell-standard"

class Accounts : public Data
{
public:
    Accounts();

    User *find(string name);

    int new_user(string name, string type, double credit);

    int del_user(string name);
//    int add_credit(string name, double amount);

    int write_accounts();


private:
    map<string, User> accounts_;
};

#endif // XSTREAM_USER_ACCOUNTS_H


