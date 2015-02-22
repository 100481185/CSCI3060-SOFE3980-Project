#include <string>
#include <iostream>
#include "login.h"
#include <iomanip>

using namespace std;

int login(session *use) {
    std::cout << USERACCOUNT_TXT << std::endl;
    if (openFile(USERACCOUNT_TXT) < 0) {
        return -1;
    }

    std::string username;
    std::cout << "Please enter your username: \n";
    std::cin >> username;



    if (checkUser(username,  use) < 0) {
        return -1;
    }
    return 0;
}


int openFile(string const fileName) {
    ifstream userAccounts;
    userAccounts.open(fileName);

    if (userAccounts.is_open()) {
        return readFile(&userAccounts);
    }
    return -1;
}

int readFile(ifstream *userAccounts) {
    ptr = accounts.begin();
    std::string line;
    while (getline(*userAccounts, line)) {
        try {
            accounts.insert(ptr, loadData(line));
        } catch (exception &e) {
            cout << e.what() << endl;
            (*userAccounts).close();
            return -1;
        }
    }
    (*userAccounts).close();
    return 0;
}


Account loadData(std::string record) {
    std::string username = record.substr(0, 14);
    std::string type_ = record.substr(16, 2);
    float credit = std::stof((record.substr(19, 9)));

    Account user(username, type_, credit);

    return user;
}


int checkUser(std::string name, session *use) {
	session sess = *use;
    name.resize(14, ' ');
    for (ptr = accounts.begin(); ptr != accounts.end(); ptr++) {
        if ((*ptr).getName() == name) {
			sess.setName((*ptr).getName());
			sess.setloggedIn(true);
			sess.setType((*ptr).getType());
            std::cout << "Hello, " << (*ptr).getName() << "\n"
                    << "\tpermission:  " << (*ptr).getType() << "\n";
            std::cout << std::setw(9);
            printf("\t    credit: $%.2f", ((*ptr).getCredit()));
            std::cout << std::endl;

            return 0;
        }
    }
    return -1;
}
