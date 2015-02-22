#include "control.h"
#include "../login/login.h"
#include "../xstream.h"
#include "../data/session.h"


using namespace std;


static Session session = Session();


int cmdManager(std::string cmd) {
    if ((!(session.getloggedIn())) && (cmd == "login")) {
        return LOGIN;
    } else if (session.getloggedIn()) {

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
            return login(session);
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











