#include "../include/session.h"

using namespace std;

int main() {
    Session session;
    int logout = 0;
    int shutdown = 0;
    string cmd;

    do {
        cout << ">>  xstream  << \n";
        do {
            std::cout << "command >>";
            std::cin >> cmd;
            logout = session.command(cmd);

            // shuts the system down when
            // cmd is end
            if (logout == 2) {
                logout = 1;
                shutdown = 1;
            }
        } while (!logout);
    } while (!shutdown);

    return 0;
}
