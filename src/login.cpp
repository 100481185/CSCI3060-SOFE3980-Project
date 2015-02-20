#include <fstream>
#include <iostream>
#include <list>
#include "login.h"

using namespace std;


int login() {
    cout << USERACCNT << endl;
    if (readFile(USERACCNT) < 0) {
        return -1;
    }

    string username;
    cout << "Please enter your username: \n";
    cin >> username;

    username.resize(14, ' ');
    if (checkUser(username) < 0) {
        return -1;
    }

    return 0;
}


int readFile(string fileName) {
    ifstream userAccounts;
    userAccounts.open(fileName);

    ptr = accounts.begin();
    string line;
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


Account loadData(string record) {
    string username = record.substr(0, 14);
    string type_ = record.substr(16, 17);
    float credit = stof(record.substr(19));

    Account user(username, type_, credit);

    return user;
}


int checkUser(string name) {
    for (ptr = accounts.begin(); ptr != accounts.end(); ptr++) {
        cout << (*ptr).getName() << ((*ptr).getName()).size()
                << name << name.size() << endl;
        if ((*ptr).getName() == name) {
            cout << "Hello " << name << endl;
            return 0;
        }
    }
    return -1;
}