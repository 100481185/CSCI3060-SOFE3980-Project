#include "../include/commit.h"

Commit::Commit(int code) : code_(to_string(code)) {
    code_.resize(CODE_SIZE, '0');
}

//string Commit::code() {
//    return code_;
//}


Refund::Refund(int code, string buyer_name, string seller_name, double credit) :
        Commit(code),
        buyer_name_(buyer_name),
        seller_name_(seller_name),
        credit_(to_string(credit)) {

    // Format attributes
    buyer_name_.resize(NAME_SIZE, ' ');
    seller_name_.resize(NAME_SIZE, ' ');
    credit_.resize(CREDIT_SIZE, '0');

    // Format the entire line - XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
    commit_ = code_ + ' ' + buyer_name_ + ' ' + seller_name_ + ' ' + credit_;
}

string Refund::commit() {
    return commit_;
}


BuySell::BuySell(int code, string event_name, string seller_name, int num_tickets, double price) :
        Commit(code),
        event_name_(event_name),
        seller_name_(seller_name),
        num_tickets_(to_string(num_tickets)),
        price_(to_string(price)) {

    // format attributes to correct sizes
    event_name_.resize(EVENT_SIZE, ' ');
    seller_name_.resize(NAME_SIZE, ' ');
    num_tickets_.resize(NUMTIC_SIZE, '0');
    price_.resize(PRICE_SIZE, '0');

    // format the entire string - XX_EEEEEEEEEEEEEEEEEEE_SSSSSSSSSSSSS_TTT_PPPPPP
    commit_ = code_ + ' ' + event_name_ + ' ' + seller_name_ + ' ' + num_tickets_ + ' ' + price_;
}

string BuySell::commit() {
    return commit_;
}


Regular::Regular(int code, string name, string type, double credit) :
        Commit(code),
        name_(name),
        type_(type),
        credit_(to_string(credit)) {

    // format attributes
    name_.resize(NAME_SIZE, ' ');
    type_.resize(TYPE_SIZE, ' ');
    credit_.resize(CREDIT_SIZE, '0');

    // format the entire string - XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
    commit_ = code_ + ' ' + name_ + ' ' + type_ + ' ' + credit_;
}

string Regular::commit() {
    return commit_;
}
