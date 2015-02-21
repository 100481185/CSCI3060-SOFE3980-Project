#include <string>
#include <iostream>

#include "login.h"
#include <fstream>
#include <iomanip>

using namespace std;

int login(bool *loggedIn, std::string *permission) {
    std::cout << USERACCNT << std::endl;
    if (readFile(USERACCNT) < 0) {
        return -1;
    }

    std::string username;
    std::cout << "Please enter your username: \n";
    std::cin >> username;

    username.resize(14, ' ');
    if (checkUser(username, loggedIn, permission) < 0) {
        return -1;
    }
    return 0;
}


int readFile(std::string const fileName) {
    ifstream userAccounts;
    userAccounts.open(fileName);

    ptr = accounts.begin();
    std::string line;
    if (userAccounts.is_open()) {
        while (getline(userAccounts, line)) {
            accounts.insert(ptr, loadData(line));
        }
        userAccounts.close();
    }
    else {
        return -1;
    }
    return 0;
}


Account loadData(std::string record) {
    std::string username = record.substr(0, 14);
    std::string type_ = record.substr(16, 2);
    float credit = std::stof((record.substr(19, 9)));

    Account user(username, type_, credit);

    return user;
}


int checkUser(std::string name, bool *loggedIn, std::string *permission) {
    for (ptr = accounts.begin(); ptr != accounts.end(); ptr++) {
        if ((*ptr).getName() == name) {
            *loggedIn = true;
            *permission = (*ptr).getType();
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
