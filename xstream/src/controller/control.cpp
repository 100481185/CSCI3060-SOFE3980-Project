#include "control.h"
#include "logout.h"
#include "create.h"
#include "../login/login.h"
#include "../xstream.h"


using namespace std;

session use;


int cmdManager(std::string cmd) {
<<<<<<< HEAD
    if ((!(session.isLoggedIn())) && (cmd == "login")) {
        return LOGIN;
    } else if (session.isLoggedIn()) {
=======
    if ((!use.getloggedIn()) && (cmd == "login")) {
        return LOGIN;
	}
	else if (use.getloggedIn()) {
>>>>>>> CS-master

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
<<<<<<< HEAD
            return login();
=======
            return login(&use);
>>>>>>> CS-master
        case LOGOUT:
//            return logout(&use);
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











