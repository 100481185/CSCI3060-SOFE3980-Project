#ifndef XSTREAM_USER_ACCOUNT_H
#define XSTREAM_USER_ACCOUNT_H

#include <iostream>
#include <list>


using namespace std;

class Account {
    std::string username;
    std::string type_;
    float credit;
public:
    Account(std::string, std::string, float);

    void setValues(std::string, std::string, float);

    std::string getName() {
        return username;
    }

    std::string getType() {
        return type_;
    }

    float getCredit() {
        return credit;
    }
};


static list<Account> accounts;
static list<Account>::iterator ptr;

#endif // XSTREAM_USER_ACCOUNT_H