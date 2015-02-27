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
        }

    } else {
        cout << INVALID;
    }
    cout << NOTLOGGED << endl;
}

int main() {

//    list<Commit> commits;

//    commits.push_back(Regular(0, "nick", "AA", 2.00));

    cout << "Xstream >> " << endl;

    string cmd;
    int check;
    while (true) {
        cout << session.logged_in() << endl;
        cin >> cmd;
        switch (cmdManager(cmd)) {
            case LOGIN:
                check = session.Login();
                break;
            case LOGOUT:
                check = session.Logout();
            case CREATE:
                check = session.Create();
                break;
            case DELETE:
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