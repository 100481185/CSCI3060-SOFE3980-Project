#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <list>

using namespace std;


class Account {
    string username, type_;
    float credit;
public:
    Account(string, string, float);

    void setValues(string, string, float);

    string getName() {
        return username;
    }

    string getType() {
        return type_;
    }

    float getCredit() {
        return credit;
    }
};


static list<Account> accounts;
static list<Account>::iterator ptr;

#endif //ACCOUNT_H