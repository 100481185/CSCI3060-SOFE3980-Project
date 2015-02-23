#include "session.h"

Session::Session(void) {
    this->setLoggedIn(false);
    this->setCredit(000000000.00);
}

void Session::setLoggedIn(bool loggedIn) {
    this->loggedIn_ = loggedIn;
}

bool Session::isLoggedIn() const {
    return this->loggedIn_;
}

void Session::setName(std::string name) {
    this->name_ = name;
}

std::string Session::getName() const {
    return this->name_;
}

void Session::setType(std::string type) {
    this->type_ = type;
}

std::string Session::getType() const {
    return this->type_;
}

void Session::setCredit(float credit) {
    this->credit_ = credit;
}

float Session::getCredit() {
    return this->credit_;
}
