#ifndef XSTREAM_COMMIT_H
#define XSTREAM_COMMIT_H

#include <iostream>

using namespace std;

#define CODE_SIZE 0
#define TYPE_SIZE 2
#define NAME_SIZE 15
#define CREDIT_SIZE 9
#define EVENT_SIZE 19
#define NUMTIC_SIZE 3
#define PRICE_SIZE 6


class Commit
{
public:
    Commit(int code);

//    string code();

    virtual string commit() {
        return commit_;
    }

    string commit_;
    string code_;

};


class Refund : public Commit
{
public:
    Refund(int code, string buyer_name, string seller_name, double credit);

    string commit();

private:
    string buyer_name_;
    string seller_name_;
    string credit_;
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
    string credit_;
};


#endif // XSTREAM_COMMIT_H

