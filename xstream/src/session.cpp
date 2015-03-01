#include "../include/xstream.h"
#include "../include/session.h"

Session::Session() {
    logged_in_ = NULL;
    transactions_ = new Transactions;
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

    logged_in_ = accounts_->find(name);
    if (!logged_in()) {
        cout << "Invalid username" << endl;
        return -1;
    }
    cout << "Welcome " << logged_in_->name() << endl;
    return 0;
}

int Session::Logout() {
    // Create a transaction for logout
    transactions_->regular(LOGOUT, logged_in_->name(), logged_in_->type(), logged_in_->credit());

    // format all transactions for txt file
    transactions_->convert_data();

    // Write the daily transaction file
    transactions_->WriteData();

    // change logged in status
    logged_in_ = NULL;

    return 0;
}

// TODO: Validate Input
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
    transactions_->regular(CREATE, name, type, credit);
    return 0;
}

int Session::Delete() {
    std::cout << "<< Delete user >>\n";

    string name;
    std::cout << "Please enter the name of the user you would like to delete: \n";;
    cin >> name;

    // Validate input
    if (name.size() > 15) {
        cout << INVALID << INPUTTOOLARGE << endl;
        return -1;
    }

    // Find user account
    User *temp = accounts_->find(name);
    // Validate that user exists
    if (temp == NULL) {
        cout << INVALID << NAMEDOESNOTEXIST << endl;
        return -1;
    }

    // delete account from memory
    int check = accounts_->del_user(name);

    // Validate from memory account was deleted
    if (check < 0) {
        cout << MEMORYERROR << USERNOTDELETED << endl;
        return -2;
    }

    // create a transaction record of the event
    transactions_->regular(DELETE, temp->name(),
                           temp->type(), temp->credit());
    return 0;
}