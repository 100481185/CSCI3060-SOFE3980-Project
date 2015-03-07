#include "../include/session.h"

using namespace std;

int main() {
    Session session;
    int logged_in = 0;
    int shutdown = 0;
    string cmd;


    do {
        cout << ">>  xstream  <<" << endl;

        do {
            std::cout << "command >>" << endl;
            std::cin >> cmd;

            logged_in = session.command(cmd);

            // shuts the system down when
            if (logged_in == 2) {
                logged_in = 1;
                shutdown = 1;
            }
        } while (session.logged_in());
    } while (!shutdown);

    return 0;
}
