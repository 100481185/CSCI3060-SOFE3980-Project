#ifndef XSTREAM_LOGIN_LOGIN_H
#define XSTREAM_LOGIN_LOGIN_H


#include <iostream>
#include "account.h"


int login(bool *loggedIn, string *permission);

int readFile(string const fileName);

Account loadData(std::string record);

int checkUser(std::string name, bool *loggedIn, std::string *permission);

string const USERACCNT = "UserAccounts.txt";

#endif // XSTREAM_LOGIN_LOGIN_H

