#ifndef XSTREAM_COMMIT_H
#define XSTREAM_COMMIT_H

#include "xstream.h"
#include <sstream>
#include <string.h>

using namespace std;




class Commit
{
public:
    Commit(int code);

    virtual string commit() {
        return commit_;
    }

    string commit_;
    char code_[CODE_SIZE];

};


class Refund : public Commit
{
public:
    Refund(int code, string buyer_name, string seller_name, double credit);

    string commit();

private:
    string buyer_name_;
    string seller_name_;
    char credit_[CREDIT_SIZE];
};


class BuySell : public Commit
{
public:
    BuySell(int code, string event_name, string seller_name, int num_tickets, double price);

    string commit();

private:
    string event_name_;
    string seller_name_;
    char num_tickets_[NUMTIC_SIZE];
    char price_[PRICE_SIZE];
};


class Regular : public Commit
{
public:
    Regular(int code, string name, string type, double credit);

    string commit();

private:
    string name_;
    string type_;
    char credit_[CREDIT_SIZE];
};

#endif // XSTREAM_COMMIT_H

