#ifndef XSTREAM_DATA_SESSION_H
#define XSTREAM_DATA_SESSION_H

#include <bits/stl_map.h>

using namespace std;

class Session
{
public:
    Session();

    void setLoggedIn(bool loggedIn);

    bool isLoggedIn() const;

    void setName(std::string name);

    std::string getName() const;

    void setType(std::string type);

    std::string getType() const;

    void setCredit(float credit);

    float getCredit();
private:
    bool loggedIn_;
    std::string name_;
    std::string type_;
    float credit_;
//    std::map<int, Transaction()> transactions_;
};

#endif