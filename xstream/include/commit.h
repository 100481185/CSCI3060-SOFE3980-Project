#ifndef XSTREAM_COMMIT_H
#define XSTREAM_COMMIT_H

#include <iostream>

using namespace std;

class Commit
{
public:
    Commit(int code);

    int code();

    virtual string commit() {
        return commit_;
    }

    string commit_;
private:
    int code_;

};


class Refund : public Commit
{
public:
    Refund(int code, string buyer_name, string seller_name, double credit);

    string commit();

private:
    string buyer_name_;
    string seller_name_;
    double credit_;
};


class BuySell : public Commit
{
public:
    BuySell(int code, string event_name, string seller_name, int num_tickets, double price);

    string commit();

private:
    int num_tickets_;
    double price_;
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
    double credit_;
};


#endif // XSTREAM_COMMIT_H

