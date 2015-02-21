#include <string>
#include <iomanip>
#include <fstream>

#include "transaction.h"
#include "account.h"
#include "logout.h"

int logout(bool *loggedIn, string *user, string *permission) {
	std::cout << USERACCNT << std::endl;
	if (read(USERACCNT) < 0) {
		return -1;
	}

	std::string username = *user; 
	if (check(username, loggedIn, permission) < 0) {
		return -1;
	}
	*user = "";
	return 0;
}

int read(std::string const fileName) {
	ifstream userAccounts;
	userAccounts.open(fileName);

	ptr = accounts.begin();
	std::string line;
	if (userAccounts.is_open()) {
		while (getline(userAccounts, line)) {
			accounts.insert(ptr, load(line));
		}
		userAccounts.close();
	}
	else {
		return -1;
	}
	return 0;
}


Account load(std::string record) {
	std::string username = record.substr(0, 14);
	std::string type_ = record.substr(16, 2);
	float credit = std::stof((record.substr(19, 9)));

	Account user(username, type_, credit);

	return user;
}

int check(std::string name, bool *loggedIn, std::string *permission) {
	for (ptr = accounts.begin(); ptr != accounts.end(); ptr++) {
		if ((*ptr).getName() == name) {
			*permission = "";
			*loggedIn = false;
			Write_Regular("00", (*ptr).getName(), (*ptr).getType(), (*ptr).getCredit());
			return 0;
		}
	}
	return -1;
}
