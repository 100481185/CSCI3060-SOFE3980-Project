#ifndef XSTREAM_USER_ACCOUNTS_H
#define XSTREAM_USER_ACCOUNTS_H

#include "../include/data.h"
#include "user.h"
#include <list>

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

    User convert_data(std::string data_line);

    User *find(std::string name);

    void new_user(string name, string type, double credit);

    int del_user(std::string name);
//    int add_credit(string name, double amount);

//    list<User> accounts_;

private:
    list<User> accounts_;
    User *ptr;
};

#endif // XSTREAM_USER_ACCOUNTS_H


