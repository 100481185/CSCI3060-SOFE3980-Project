#include "login.h"
#include "control.h"


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
    std::cout << "Xstream" << std::endl;

    std::cout << "Enter your command: " << std::endl;
    std::string cmd;
    std::cin >> cmd;

    int check;
    check = cmdFilter(cmd);

    switch (check) {
        case 0:
            check = login(&loggedIn);
            std::cout << loggedIn << std::endl;
            break;
        case 1:
            break;
        default:
            break;
    }
    return check;
}











