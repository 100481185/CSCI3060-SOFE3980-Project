#ifndef XSTREAM_COMMIT_H
#define XSTREAM_COMMIT_H

#include <sstream>
#include <string.h>

using namespace std;

#define CODE_SIZE 2
#define TYPE_SIZE 2
#define NAME_SIZE 15
#define CREDIT_SIZE 9
#define EVENT_SIZE 19
#define NUMTIC_SIZE 3
#define PRICE_SIZE 6

#define CODE_FORMAT "%02i"
#define NAME_FORMAT "%15s"
#define TYPE_FORMAT "%2s"
#define CREDIT_W_DEC_FORMAT "%09.2f"
#define CREDIT_WO_DEC_FORMAT "%09i"


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
    char buyer_name_[NAME_SIZE];
    char seller_name_[NAME_SIZE];
    char credit_[CREDIT_SIZE];
};


class BuySell : public Commit
{
public:
    BuySell(int code, string event_name, string seller_name, int num_tickets, double price);

    string commit();

private:
    string num_tickets_;
    string price_;
    string seller_name_;
    string event_name_;
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

