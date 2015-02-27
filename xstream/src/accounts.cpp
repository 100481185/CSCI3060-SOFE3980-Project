#include "../include/accounts.h"

Accounts::Accounts() :
        Data() {

    set_file_name(USER_ACCOUNTS);

    if (ReadData() == 0) {
        list<string>::iterator data_ptr = data_.begin();
        for (data_ptr; data_ptr != data_.end(); data_ptr++) {
            string da = *data_ptr;
            accounts_.push_back(convert_data(*data_ptr));
        }
    }
}

User Accounts::convert_data(string data_line) {
    string name = data_line.substr(0, 14);
    string type = data_line.substr(16, 2);
    double credit = stod((data_line.substr(19, 9)));
    return User(name, type, credit);
}

User *Accounts::find(string name) {
    name.resize(14, ' ');
    list<User>::iterator account_ptr = accounts_.begin();

    while (account_ptr != accounts_.end()) {
        if ((*account_ptr).name() == name)
            return &(*account_ptr);
        else
            account_ptr++;
    }
    return NULL;
}

void Accounts::new_user(string name, string type, double credit) {
    accounts_.push_back(User(name, type, credit));
}

int Accounts::del_user(string name) {
//    User * user = find(name);
//    accounts_.remove(*user);
    return 0;
}
