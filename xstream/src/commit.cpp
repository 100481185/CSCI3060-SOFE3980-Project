#include "../include/commit.h"

Commit::Commit(int code) : code_(code) {
}

int Commit::code() {
    return code_;
}


Refund::Refund(int code, string buyer_name, string seller_name, double credit) :
        Commit(code),
        buyer_name_(buyer_name),
        seller_name_(seller_name),
        credit_(credit) {
    commit_ = to_string(code) + ' ' + buyer_name_ + ' ' + seller_name_ + ' ' + to_string(credit_);
}

string Refund::commit() {
    return commit_;
}


BuySell::BuySell(int code, string event_name, string seller_name, int num_tickets, double price) :
        Commit(code),
        event_name_(event_name),
        seller_name_(seller_name),
        num_tickets_(num_tickets),
        price_(price) {
    commit_ = to_string(code) + ' ' + event_name_ + ' ' + to_string(num_tickets_) + ' ' + to_string(price_);
}

string BuySell::commit() {
    return commit_;
}


Regular::Regular(int code, string name, string type, double credit) :
        Commit(code),
        name_(name),
        type_(type),
        credit_(credit) {
    commit_ = to_string(code) + ' ' + name_ + ' ' + type_ + ' ' + to_string(credit_);
}

string Regular::commit() {
    return commit_;
}
