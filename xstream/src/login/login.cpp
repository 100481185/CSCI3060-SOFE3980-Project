#include <string>
#include <iostream>

#include "login.h"
#include <fstream>

using namespace std;

int login(bool *loggedIn) {
    std::cout << USERACCNT << std::endl;
    if (readFile(USERACCNT) < 0) {
        return -1;
    }

    std::string username;
    std::cout << "Please enter your username: \n";
    std::cin >> username;

    username.resize(14, ' ');
    if (checkUser(username, loggedIn) < 0) {
        return -1;
    }

    return 0;
}


int readFile(string const fileName) {
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
    std::string type_ = record.substr(16, 17);
    float credit = std::stof((record.substr(19)));

    Account user(username, type_, credit);

    return user;
}


int checkUser(std::string name, bool *loggedIn) {
    for (ptr = accounts.begin(); ptr != accounts.end(); ptr++) {
        std::cout << (*ptr).getName() << ((*ptr).getName()).size()
                << name << name.size() << std::endl;
        if ((*ptr).getName() == name) {
            std::cout << "Hello " << name << std::endl;
            *loggedIn = true;
            return 0;
        }
    }
    return -1;
}