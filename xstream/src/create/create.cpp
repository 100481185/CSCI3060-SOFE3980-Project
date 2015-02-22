#include <fstream>
#include <string>

#include "transaction.h"
#include "account.h"
#include "create.h"

int create(){
	std::cout << USERACCNT << std::endl;
	if (readAccountFile(USERACCNT) < 0) {
		return -1;
	}

	std::string username_new, type_new;
	float credit_new;

	std::cout << "Please enter new username: \n";
	std::cin >> username_new;
	if (username_new.length() > 15 || checkAccounts(username_new)) {
		return -1;
	}

	std::cout << "Please enter type: \n";
	std::cin >> type_new;
	if (type_new.length() != 2){
		return -1;
	}

	std::cout << "Please enter credit: \n";
	std::cin >> credit_new;
	if (credit_new > 1000000){
		return -1;
	}

	//update list of accounts here (if necessary)
	
	Write_Regular("01", username_new, type_new, credit_new);
	return 0;
}


int readAccountFile(std::string const fileName) {
	ifstream userAccounts;
	userAccounts.open(fileName);

	ptr = accounts.begin();
	std::string line;
	if (userAccounts.is_open()) {
		while (getline(userAccounts, line)) {
			accounts.insert(ptr, loadAccounts(line));
		}
		userAccounts.close();
	}
	else {
		return -1;
	}
	return 0;
}


Account loadAccounts(std::string record) {
	std::string username = record.substr(0, 14);
	std::string type_ = record.substr(16, 2);
	float credit = std::stof((record.substr(19, 9)));

	Account user(username, type_, credit);

	return user;
}

int checkAccounts(std::string name) {
	for (ptr = accounts.begin(); ptr != accounts.end(); ptr++) {
		if ((*ptr).getName() == name) {
			return -1;
		}
	}
	return 0;
}
