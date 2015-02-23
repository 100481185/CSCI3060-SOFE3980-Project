#ifndef XSTREAM_USER_ACCOUNT_H
#define XSTREAM_USER_ACCOUNT_H

#include <iostream>
#include <list>
#include "session.h"


using namespace std;

#define USERACCOUNT_TXT "../xstream/src/data/user/UserAccounts.txt"

class Account {
public:
    Account(std::string, std::string, float);

    void setValues(std::string, std::string, float);

    std::string getName() {
        return username_;
    }

    std::string getType() {
        return type_;
    }

    float getCredit() {
        return credit;
    }

private:
    std::string username_;
    std::string type_;
    float credit;
};

string const USERACCNT = "UserAccounts.txt";

static list<Account> accounts;
static list<Account>::iterator ptr;

#endif // XSTREAM_USER_ACCOUNT_H
