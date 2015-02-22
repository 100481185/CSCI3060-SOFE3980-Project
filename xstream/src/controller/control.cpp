#include "control.h"
#include "../login/login.h"
#include "../xstream.h"

using namespace std;


int cmdManager(std::string cmd) {
    if ((!loggedIn) && (cmd == "login")) {
        return LOGIN;
    } else if (loggedIn) {

    } else {
        cout << INVALID;
    }
    cout << NOTLOGGED << endl;
}


int control() {
    std::cout << "Xstream >> " << std::endl;
    std::string cmd;
    std::cin >> cmd;

    switch (cmdManager(cmd)) {
        case LOGIN:
            return login(&loggedIn, &permission);
        case LOGOUT:
//            return logout();
        case CREATE:
//            return create();
        case DELETE:
        case SELL:
        case BUY:
        case REFUND:
        case ADDCREDIT:
        default:
            return -1;
    }
}











