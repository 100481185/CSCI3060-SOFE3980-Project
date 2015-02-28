#ifndef XSTREAM_DAILY_TRANSACTIONS_H
#define XSTREAM_DAILY_TRANSACTIONS_H

#include "../include/data.h"
#include "../include/commit.h"
#include <iostream>

using namespace std;

#define TRANSACTIONS "data/DailyTransactions.txt"

class Transactions : public Data
{
public:
    Transactions();

    int convert_data();

    int refund(int code, string username, string type_, double credit);

    int buy_sell(int code, string buyer_name, string seller_name, int num_tickets, double price);

    int regular(int code, string name, string type, double credit);

//    int Write_Refund(string code, string username, string type_, float credit);

private:
    list<Commit> commits_;
};

#endif
