#ifndef XSTREAM_LOGOUT_LOGOUT_H
#define XSTREAM_LOGOUT_LOGOUT_H

int logout(bool *loggedIn, string *user, string *permission);

int read(string const fileName);

Account load(std::string record);

int check(std::string name, bool *loggedIn, std::string *permission);


#endif
