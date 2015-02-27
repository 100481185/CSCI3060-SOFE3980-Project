#ifndef XSTREAM_USER_ACCOUNT_H
#define XSTREAM_USER_ACCOUNT_H

#include <iostream>
#include <list>

using namespace std;

class User
{
public:

    User();

    User(string name, string type, double credit);

    void set_name(string name);

    string name();

    void setType(string type);

    string type() const;

    void setCredit(double credit);

    double credit();

private:
    string name_;
    string type_;
    double credit_;
};

#endif // XSTREAM_USER_ACCOUNT_H
