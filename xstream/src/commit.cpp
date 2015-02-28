#include "../include/commit.h"

Commit::Commit(int code) {
    sprintf(code_, CODE_FORMAT, code);
}


Refund::Refund(int code, string buyer_name, string seller_name, double credit) :
        Commit(code) {

    // Format attributes
    sprintf(buyer_name_, NAME_FORMAT, buyer_name.c_str());
    sprintf(seller_name_, NAME_FORMAT, seller_name.c_str());
    if (credit == int(credit))
        sprintf(credit_, CREDIT_WO_DEC_FORMAT, (int) credit);
    else
        sprintf(credit_, CREDIT_W_DEC_FORMAT, credit);

    // Format the entire line - XX_UUUUUUUUUUUUUUU_SSSSSSSSSSSSSSS_CCCCCCCCC
    stringstream temp;
    temp << code_ << ' ' << buyer_name_ << ' ' << seller_name_ << ' ' << credit_;
    commit_ = temp.str();
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
    stringstream temp;
    temp << code_ << ' ' << event_name_ << ' ' << seller_name_ << ' ' << num_tickets_ << ' ' << price_;
    commit_ = temp.str();
}

string BuySell::commit() {
    return commit_;
}


Regular::Regular(int code, string name, string type, double credit) :
        Commit(code),
        name_(name),
        type_(type) {

    // format attributes
    name_.resize(NAME_SIZE, ' ');
    type_.resize(TYPE_SIZE, ' ');
    if (credit == int(credit))
        sprintf(credit_, CREDIT_WO_DEC_FORMAT, (int) credit);
    else
        sprintf(credit_, CREDIT_W_DEC_FORMAT, credit);

    // format the entire string - XX_UUUUUUUUUUUUUUU_TT_CCCCCCCCC
    stringstream temp;
    temp << code_ << ' ' << name_ << ' ' << type_ << ' ' << credit_;
    commit_ = temp.str();
}

string Regular::commit() {
    return commit_;
}
