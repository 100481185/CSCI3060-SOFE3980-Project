#include "account.h"

using namespace std;

Account::Account(string username, string type_, float credit) {
    setValues(username, type_, credit);
}

void Account::setValues(string userName, string Type_, float Credit) {
    username = userName;
    type_ = Type_;
    credit = Credit;
}

