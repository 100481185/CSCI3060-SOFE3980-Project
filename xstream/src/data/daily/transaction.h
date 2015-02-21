#ifndef XSTREAM_DAILY_TRANSACTIONS_H
#define XSTREAM_DAILY_TRANSACTIONS_H

#include <iostream>

using namespace std;

int Write_Regular(string code, string username, string type_, float credit);

int Write_Refund(string code, string username_buyer, string username_seller, float credit_refund);

int Write_BuySell(string code, string event, string username_seller, int tickets, float price);

string const TRANSACTION = "DailyTransaction.txt";

#endif
