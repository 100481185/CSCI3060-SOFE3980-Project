#include "control.h"
#include "../login/login.h"
#include "../xstream.h"


using namespace std;


int cmdManager(std::string cmd) {
    if ((!(session.isLoggedIn())) && (cmd == "login")) {
        return LOGIN;
    } else if (session.isLoggedIn()) {

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
            return login();
        case LOGOUT:
//            return logout();
        case CREATE:
        case DELETE:
        case SELL:
        case BUY:
        case REFUND:
        case ADDCREDIT:
        default:
            return -1;
    }
}











