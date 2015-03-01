#include "../include/transaction.h"

Transactions::Transactions() :
		Data() {
	set_file_name(TRANSACTIONS);
}

int Transactions::refund(int code, string username, string type, double credit) {
	commits_.push_back(Refund(code, username, type, credit));
	return 0;
}

int Transactions::buy_sell(int code, string event_name, string seller_name, int num_tickets, double price) {
	commits_.push_back(BuySell(code, event_name, seller_name, num_tickets, price));
	return 0;
}

int Transactions::regular(int code, string name, string type, double credit) {
	Regular reg(code, name, type, credit);
	commits_.push_back(reg);
	return 0;
}

int Transactions::write_transactions() {
	list<Commit>::iterator ptr = commits_.begin();
	for (ptr; ptr != commits_.end(); ptr++) {
		data_.push_back(ptr->commit());
	}
	return 0;
}


