#include "../include/user.h"

using namespace std;

User::User() {

}

User::User(string name, string type, double credit) :
        name_(name),
        type_(type),
        credit_(credit) {
}

void User::set_name(string name) {
    name_ = name;
}

string User::name() {
    return name_;
}

void User::setType(string type) {
    type_ = type;
}

string User::type() const {
    return type_;
}

void User::setCredit(double credit) {
    credit_ = credit;
}

double User::credit() {
    return credit_;
}





