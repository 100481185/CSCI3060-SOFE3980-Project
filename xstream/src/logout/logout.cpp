#include "logout.h"

#include <string>
#include <iomanip>
#include <fstream>

#include "../data/daily/transaction.h"
#include "../data/user/account.h"

session sess;
int logout(session *use) {
	sess = *use;
	std::cout << USERACCNT << std::endl;
	if (read(USERACCNT) < 0) {
		return -1;
	}

	if (check(sess.getName(), use) < 0) {
		return -1;
	}
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

int check(std::string name, session *use) {
	for (ptr = accounts.begin(); ptr != accounts.end(); ptr++) {
		if ((*ptr).getName() == name) {
			sess.setloggedIn(false);
			sess.setType("");
			sess.setName("");
			Write_Regular("00", (*ptr).getName(), (*ptr).getType(), (*ptr).getCredit());
			return 0;
		}
	}
	return -1;
}
