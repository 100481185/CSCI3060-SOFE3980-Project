#include "../include/xstream.h"
#include "../include/session.h"

Session::Session(bool silent) {
    silent_ = silent;
    logged_in_ = NULL;
    transactions_ = new Transactions;
}

bool Session::logged_in() const {
    return (logged_in_ != NULL);
}

int Session::command(string cmd) {
    if (!logged_in()) {
        if (cmd == "login")
            return Login();
        if (cmd == "end")
            return 2;

    } else if (logged_in()) {

        if (cmd == "logout")
            return Logout();

        else if (cmd == "create")
            return Create();

        else if (cmd == "delete")
            return Delete();

        else if (cmd == "sell")
            return Sell();

        else if (cmd == "buy")
            return Buy();

        else if (cmd == "refund")
            return Refund();

        else if (cmd == "addcredit")
            return AddCredit();
    } else
        cout << INVALID;
    cout << NOTLOGGED << endl;
    return 0;
}

// TODO: Validate input
// TODO: Create Login test suite
int Session::Login() {
    // initialize accounts
    accounts_ = new Accounts;

    std::string name;
    if (!silent_)
        std::cout << ">> Please enter your username: \n";
    std::cin >> name;

    logged_in_ = accounts_->find(name);
    if (!logged_in()) {
        cout << "Invalid username" << endl;
        return -1;
    }

    if (!silent_)
        cout << ">> Welcome " << logged_in_->name() << endl;
    else
        cout << logged_in_->name() << endl;

    // read in ticket file
    tickets_ = new Tickets;

    if (!silent_) {
        tickets_->print_tickets();
    }

    return 0;
}

// TODO: Create Logout test suite
int Session::Logout() {
    // Create a transaction for logout
    transactions_->regular(LOGOUT, logged_in_->name(), logged_in_->type(), logged_in_->credit());

    // write updated events to AvailableTickets file
    tickets_->write_events();

    // write transactions to DailyTransactions file
    transactions_->write_transactions();

    // change logged in status
    logged_in_ = NULL;

    if (!silent_) {
        cout << "Logout Successfull";
    } else {
        cout << logged_in() << endl;
    }
    return 1;
}

// TODO: Validate Create() Input
// TODO: Create test suite
int Session::Create() {
    if(logged_in_->type() != "AA"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }

    if (!silent_) {
        std::cout << ">> Create new user <<\n";
        std::cout << ">> Please enter the name of the new user: \n";;
    }

    string name;
    cin >> name;
    if ((name.size() > NAME_SIZE)){
	cout << INVALID << INPUTTOOLARGE << endl;
	return -1;
    }
    if (accounts_->find(name) != NULL) {
        cout << INVALID << NAMEEXISTS << endl;
        return -1;
    }

    if (!silent_)
        std::cout << ">>Please enter type: \n";

    string type;
    std::cin >> type;
    if (type.length() != TYPE_SIZE) {
        cout << INVALID << INVALIDTYPE << endl;
        return -1;
    }

    if (!silent_)
        std::cout << ">>Please enter credit: \n";

    double credit;
    std::cin >> credit;
    if (credit >= 999999999) {
	cout << INVALID << INPUTTOOLARGE << endl;
        return -1;
    }

    // update list of accounts here (if necessary)
    accounts_->new_user(name, type, credit);
    // create a transaction record of the event
    transactions_->regular(CREATE, name, type, credit);
    // write updated accounts to UserAccounts file
    accounts_->write_accounts();

    User *test = accounts_->find(name);
    if (!logged_in_) {
        cout << "Create " << (*accounts_->find(name)).name() << " was Succesfull" << endl;
    } else {
        cout << test->name() << endl;
        cout << test->type() << endl;
        cout << test->credit() << endl;
    }


    return 0;
}

// TODO: Create Delete test suite
int Session::Delete() {
    if(logged_in_->type() != "AA"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }

    if (!silent_) {
        std::cout << ">> Delete user <<\n";
        std::cout << ">> Please enter the name of the user you would like to delete: \n";;
    }
    string name;
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

    // user cannot delete their own account
    if (name == logged_in_->name()) {
	cout << INVALID << SELFDELETE << endl;
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
    // write updated accounts to UserAccounts file
    accounts_->write_accounts();
    return 0;
}

// TODO: Sell test suite
int Session::Sell() {
    if(logged_in_->type() == "BS"){
        std::cout << BADACCESS << std::endl;
        return -1;
    }

    if (!silent_) {
        cout << ">> Sell tickets for event <<" << endl;
        std::cout << ">> Please enter the name of the event: \n";;
    }

    string event;
    cin >> event;

    // Validate input
    if (event.size() > EVENT_SIZE) {
        cout << INVALID << INPUTTOOLARGE << endl;
        return -1;
    }

    // Check if event exists
    // Validate that event exists
    if (tickets_->find_event(event) != NULL) {
        cout << INVALID << NAMEEXISTS << endl;
        return -1;
    }


    if (!silent_) {
        std::cout << ">> Please enter price per ticket: \n";
    }

    double price;
    std::cin >> price;
    if (price >= 1000) {
	std::cout << PRICETOOHIGH << std::endl;
        return -1;
    }

    if (!silent_) {
        std::cout << ">> Please enter number of tickets to be available: \n";
    }

    int num_tickets;
    std::cin >> num_tickets;
    if (num_tickets > 100) {
	std::cout << TOOMUCHTICKETS << std::endl;
        return -1;
    } 
    
    // update list of events
    tickets_->new_event(event, logged_in_->name(), num_tickets, price);
    // create a transaction record of the event
    transactions_->buy_sell(SELL, event, logged_in_->name(), num_tickets, price);
    return 0;
}

// TODO: Buy test suite
int Session::Buy() {
    if(logged_in_->type() == "SS"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }

    if (!silent_) {
        std::cout << ">> Purchase tickets to event >>\n";
        std::cout << ">> Please enter the name of the event: \n";;
    }

    string event;
    cin >> event;

    // Validate input
    if (event.size() > EVENT_SIZE) {
        cout << INVALID << INPUTTOOLARGE << endl;
        return -1;
    }

    // Check if event exists
    // Validate that event exists
    Event *e = tickets_->find_event(event);
    if (e == NULL) {
        cout << INVALID << NAMEDOESNOTEXIST << endl;
        return -1;
    }


    if (!silent_) {
        std::cout << ">> Please enter the name of the seller: \n";;
    }

    string seller;
    cin >> seller;

    User *seller_ = accounts_->find(seller);
    if (seller.size() > NAME_SIZE) {
	cout << INVALID << INPUTTOOLARGE << endl;
	return -1;
    }

    if (seller_ == NULL) {
        cout << INVALID << NAMEDOESNOTEXIST << endl;
        return -1;
    }

    if (seller != e->seller()) {
	cout << INVALID << NOTSELLER << endl;
	return -1;
    }

    if (!silent_) {
        std::cout << ">> Please enter number of tickets to purchase: \n";
    }

    int num_tickets;
    std::cin >> num_tickets;
    if (num_tickets > e->num_tickets() || (num_tickets > 4 && logged_in_->type() != "AA")) {
	std::cout << TOOMUCHTICKETS << std::endl;
        return -1;
    }
    double total_cost = (num_tickets * e->price());


    if (!silent_) {
        std::cout << ">> This event costs " << e->price() << " dollars per ticket." << endl;
        std::cout << ">> The total cost for your purchase is " << total_cost << " dollars." << endl;
        std::cout << ">> Would you like to confirm this purchase? (Y/N)" << endl;
    } else {
        std::cout << e->price() << endl;
        std::cout << total_cost << endl;
    }

    string decision;
    std::cin >> decision;
    if(decision != "Y"){
	std::cout << ">>Transaction cancelled." << std::endl;
	return -1;
    }

    if(total_cost > logged_in_->credit()){
	std::cout << INSUFFICIENTFUNDS << std::endl;
	return -1;
    }

    e->setNumTickets(e->num_tickets() - num_tickets);
    logged_in_->setCredit(logged_in_->credit() - total_cost);
    // create a transaction record of the event
    transactions_->buy_sell(BUY, event, logged_in_->name(), num_tickets, e->price());
    return 0;
}

// TODO: Refund test suite
int Session::Refund() {
    if(logged_in_->type() != "AA"){
	std::cout << BADACCESS << std::endl;
	return -1;
    }

    if (!silent_) {
        std::cout << ">> Issue credit between accounts >>\n";
        std::cout << ">> Please enter the name of the buyer: \n";;
    }

    string buyer;
    cin >> buyer;
    User *buyer_ = accounts_->find(buyer);
    if (buyer.size() > NAME_SIZE) {
	cout << INVALID << INPUTTOOLARGE << endl;
    } 

    if (buyer_ == NULL) {
        cout << INVALID << NAMEDOESNOTEXIST << endl;
        return -1;
    }

    if (!silent_) {
        std::cout << ">> Please enter the name of the seller: \n";;
    }

    string seller;
    cin >> seller;
    User *seller_ = accounts_->find(seller);
    if (seller.size() > NAME_SIZE) {
	cout << INVALID << INPUTTOOLARGE << endl;
    }

    if (seller_ == NULL) {
        cout << INVALID << NAMEDOESNOTEXIST << endl;
        return -1;
    }

    if (!silent_) {
        std::cout << ">> Please enter credit to be transferred: \n";
    }

    double credit;
    std::cin >> credit;
    if (credit >= 999999999 || credit > seller_->credit() || credit + buyer_->credit() >= 999999999) {
	cout << INVALID << INPUTTOOLARGE << endl;
        return -1;
    }    

    seller_->setCredit(seller_->credit() - credit);
    buyer_->setCredit(buyer_->credit() + credit);

    // create a transaction record of the event
    transactions_->refund(REFUND, buyer, seller, credit);
    return 0;
}

// TODO: AddCredit test suite
int Session::AddCredit() {

    if (!silent_) {
        std::cout << ">> Add Credit >>\n";
    }


    User *buyer_;
    if(logged_in_->type() == "AA"){

        if (!silent_) {
            std::cout << ">> Please enter the name of the buyer: \n";;
        }

        string buyer;
	    cin >> buyer;
	    buyer_ = accounts_->find(buyer);
    	    if (buyer.size() > NAME_SIZE) {
	    	cout << INVALID << INPUTTOOLARGE << endl;
    		return -1;
	    } 

	    if (buyer_ == NULL) {
	        cout << INVALID << NAMEDOESNOTEXIST << endl;
	        return -1;
	    }

    } else buyer_ = logged_in_;


    if (!silent_) {
        std::cout << ">> Please enter credit to be added: \n";
    }

    double credit;
    std::cin >> credit;
    if (credit > 1000 || credit + buyer_->credit() >= 999999999) {
	cout << INVALID << INPUTTOOLARGE << endl;
        return -1;
    } 

    buyer_->setCredit(buyer_->credit() + credit);

    if (!silent_) {
        cout << "$" << credit << " added to "<< buyer_->name() << ": credit=$" << buyer_->credit() << endl;
    } else {
        cout << buyer_->name() << endl;
        cout << buyer_->credit() << endl;
    }

    // create a transaction record of the event
    transactions_->regular(ADDCREDIT, buyer_->name(), buyer_->type(), buyer_->credit());

    return 0;
}
