#ifndef XSTREAM_INCLUDE_USER_H
#define XSTREAM_INCLUDE_USER_H

#include "xstream.h"
#include <iostream>
#include <sstream>
#include <list>

using namespace std;

class User
{
public:

    User();

    User(string name, string type, double credit);

    string name();

    string type() const;

    double credit();

    string user() const;

    void set_name(string name);
    void setType(string type);
    void setCredit(double credit);

private:
    string name_;
    string type_;
    double credit_;
};

#endif // XSTREAM_INCLUDE_USER_H

