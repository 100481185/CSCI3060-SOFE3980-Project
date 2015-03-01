#include "../include/xstream.h"
#include "../include/session.h"

using namespace std;


Session session;

int cmdManager(std::string cmd) {

    if (cmd == "end") {
        return END;
    }

    if (cmd == "login" && !session.logged_in()) {
        return LOGIN;

    } else if (session.logged_in()) {
        if (cmd == "logout") {
            return LOGOUT;

        } else if (cmd == "create") {
            return CREATE;
        } else if (cmd == "delete") {
            return DELETE;
        }


    } else {
        cout << INVALID;
    }
    cout << NOTLOGGED << endl;
}

int main() {

    cout << "Xstream >> " << endl;

    string cmd;
    int check;
    while (true) {
        cout << "command >>" << endl;
        cin >> cmd;
        switch (cmdManager(cmd)) {
            case LOGIN:
                check = session.Login();
                break;
            case LOGOUT:
                check = session.Logout();
                break;
            case CREATE:
                check = session.Create();
                break;
            case DELETE:
                check = session.Delete();
                break;
            case SELL:
            case BUY:
            case REFUND:
            case ADDCREDIT:
            case END:
                return 0;
            default:
                break;
        }
    }
    return 0;
}
