#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>
#include "account.h"


using namespace std;

int readFile(string fileName);

Account loadData(string record);

int checkUser(string name);

const string USERACCNT = "/home/nicholas/ClionProjects/QandA/data/UserAccounts.txt";

#endif //LOGIN_H