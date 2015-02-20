#ifndef XSTREAM_LOGIN_H
#define XSTREAM_LOGIN_H


#include <iostream>
#include "account.h"


int login(bool *loggedIn);

int readFile(string const fileName);

Account loadData(std::string record);

int checkUser(std::string name, bool *loggedIn);

string const USERACCNT = "/home/nicholas/ClionProjects/QandA/data/UserAccounts.txt";

#endif // XSTREAM_LOGIN_H

