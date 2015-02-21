#include "control.h"
#include "../login/login.h"
#include "../logout/logout.h"


bool loggedIn = false;
bool admin = false;


int cmdFilter(std::string cmd) {
    if ((cmd == "login") && (!loggedIn)) {
        return 0;
    } else {
        return -1;
    }
}


int control() {
    std::cout << "Xstream >> " << std::endl;
    std::string cmd;
    std::cin >> cmd;

    switch (cmdFilter(cmd)) {
        case 0:
            return login(&loggedIn);
        case 1:
            return logout();
        default:
            return -1;
    }
}











