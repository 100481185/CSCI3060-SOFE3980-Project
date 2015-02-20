#ifndef XSTREAM_H
#define XSTREAM_H

#include <iostream>
#include <string>

using namespace std;

int cmdFilter(std::string cmd, bool loggedIn);

int login();

bool loggedIn = false;
bool admin = false;

#endif


