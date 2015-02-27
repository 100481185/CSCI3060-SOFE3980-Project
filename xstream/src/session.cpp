#include "../include/xstream.h"
#include "../include/session.h"

Session::Session() {
    logged_in_ = NULL;
    commits_ = new Transactions;
}

bool Session::logged_in() const {
    return (logged_in_ != NULL);
}

int Session::Login() {
    // initialize accounts
    accounts_ = new Accounts;

    std::string name;
    std::cout << "Please enter your username: \n";
    std::cin >> name;

    logged_in_ = (accounts_->find(name));
    if (!logged_in()) {
        cout << "Invalid username" << endl;
        return -1;
    }
    cout << "Welcome " << logged_in_->name() << endl;
    return 0;
}

int Session::Logout() {
    // format all transactions
    commits_->convert_data();

    // Write the daily transaction file
    commits_->WriteData();

    // change logged in status
    logged_in_ = NULL;

    return 0;
}

int Session::Create() {
    std::cout << "<< Create new user >>\n";

    string name;
    std::cout << "Please enter the name of the new user: \n";;
    cin >> name;
    if ((name.size() > 15) || (accounts_->find(name) != NULL)) {
        cout << INVALID << NAMEEXISTS << endl;
        return -1;
    }

    string type;
    std::cout << "Please enter type: \n";
    std::cin >> type;
    if (type.length() != 2) {
        cout << INVALID << INVALIDTYPE << endl;
        return -1;
    }

    double credit;
    std::cout << "Please enter credit: \n";
    std::cin >> credit;
    if (credit >= 999999999) {
        return -1;
    }

    // update list of accounts here (if necessary)
    accounts_->new_user(name, type, credit);
    // create a transaction record of the event
    commits_->regular(CREATE, name, type, credit);
    return 0;
}

int Session::Delete() {
    return 0;
}