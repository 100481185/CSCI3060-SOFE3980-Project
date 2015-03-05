#include "../include/xstream.h"
#include "../include/session.h"

Session::Session() {
    logged_in_ = NULL;
    transactions_ = new Transactions;
}

bool Session::logged_in() const {
    return (logged_in_ != NULL);
}

// TODO: Validate input
// TODO: Create Login test suite
int Session::Login() {
    // initialize accounts and event data
    accounts_ = new Accounts;
    tickets_ = new Tickets;

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

// TODO: Create Logout test suite
int Session::Logout() {
    // Create a transaction for logout
    transactions_->regular(LOGOUT, logged_in_->name(), logged_in_->type(), logged_in_->credit());

    // write updated accounts to UserAccounts file
    accounts_->write_accounts();

    // write updated events to AvailableTickets file
    tickets_->write_events();

    // write transactions to DailyTransactions file
    transactions_->write_transactions();

    // change logged in status
    logged_in_ = NULL;

    return 0;
}

// TODO: Validate Create() Input
// TODO: Create test suite
int Session::Create() {
    if(logged_in_->type() != "AA"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }

    std::cout << "<< Create new user >>\n";

    string name;
    std::cout << "Please enter the name of the new user: \n";;
    cin >> name;
    if ((name.size() > NAME_SIZE) || (accounts_->find(name) != NULL)) {
        cout << INVALID << NAMEEXISTS << endl;
        return -1;
    }

    string type;
    std::cout << "Please enter type: \n";
    std::cin >> type;
    if (type.length() != TYPE_SIZE) {
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

// TODO: Create Delete test suite
int Session::Delete() {
    if(logged_in_->type() != "AA"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }

    std::cout << "<< Delete user >>\n";

    string name;
    std::cout << "Please enter the name of the user you would like to delete: \n";;
    cin >> name;

    // Validate input
    if (name.size() > NAME_SIZE) {
        cout << INVALID << INPUTTOOLARGE << endl;
        return -1;
    }

    // Check if user exists
    // Validate that user exists
    if (accounts_->find(name) == NULL) {
        cout << INVALID << NAMEDOESNOTEXIST << endl;
        return -1;
    }

    // make a local copy of User
    User temp = *accounts_->find(name);

    // delete account from memory
    int check = accounts_->del_user(name);

    // Validate from memory account was deleted
    if (check < 0) {
        cout << MEMORYERROR << USERNOTDELETED << endl;
        return -2;
    }

    // create a transaction record of the event
    transactions_->regular(DELETE, temp.name(), temp.type(), temp.credit());
    return 0;
}

// TODO: Implement Sell()
// TODO: Sell test suite
int Session::Sell() {
    if(logged_in_->type() == "BS"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }
    std::cout << "<< Sell tickets for event >>\n";
    return 0;
}

// TODO: Implement Buy()
// TODO: Buy test suite
int Session::Buy() {
    if(logged_in_->type() == "SS"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }
    std::cout << "<< Purchase tickets to event >>\n";
    return 0;
}

// TODO: Implement Refund()
// TODO: Refund test suite
int Session::Refund() {
    if(logged_in_->type() != "AA"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }

    std::cout << "<< Issue credit between accounts >>\n";

    string buyer;
    std::cout << "Please enter the name of the buyer: \n";;
    cin >> buyer;
    User *buyer_ = accounts_->find(buyer);
    if ((buyer.size() > NAME_SIZE) || (buyer_ == NULL)) {
        cout << INVALID << NAMEDOESNOTEXIST << endl;
        return -1;
    }

    string seller;
    std::cout << "Please enter the name of the seller: \n";;
    cin >> seller;
    User *seller_ = accounts_->find(seller);
    if ((seller.size() > NAME_SIZE) || (seller_ == NULL)) {
        cout << INVALID << NAMEDOESNOTEXIST << endl;
        return -1;
    }

    double credit;
    std::cout << "Please enter credit to be transferred: \n";
    std::cin >> credit;
    if (credit >= 999999999 || credit > seller_->credit() || credit + buyer_->credit() >= 999999999) {
        return -1;
    }    

    seller_->setCredit(seller_->credit() - credit);
    buyer_->setCredit(buyer_->credit() + credit);

    // create a transaction record of the event
    transactions_->refund(REFUND, buyer, seller, credit);
    return 0;
}

// TODO: Implement AddCredit()
// TODO: AddCredit test suite
int Session::AddCredit() {
    std::cout << "<< Add Credit >>\n";
    User *buyer_;
    
    if(logged_in_->type() == "AA"){
	    string buyer;
	    std::cout << "Please enter the name of the buyer: \n";;
	    cin >> buyer;
	    buyer_ = accounts_->find(buyer);
	    if ((buyer.size() > NAME_SIZE) || (buyer_ == NULL)) {
	        cout << INVALID << NAMEDOESNOTEXIST << endl;
	        return -1;
	    }

    } else buyer_ = logged_in_;	

    double credit;
    std::cout << "Please enter credit to be added: \n";

    std::cin >> credit;
    if (credit > 1000 || credit + buyer_->credit() >= 999999999) {
        return -1;
    } 

    buyer_->setCredit(buyer_->credit() + credit);
    // create a transaction record of the event
    transactions_->regular(ADDCREDIT, buyer_->name(), buyer_->type(), buyer_->credit());

    return 0;
}
