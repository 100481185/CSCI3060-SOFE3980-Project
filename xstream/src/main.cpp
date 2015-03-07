#include "../include/session.h"

using namespace std;

int main(int argc, char **argv) {
    bool silent;
    if(argc > 1)
        silent = (strcmp(argv[1], "-s") == 0);
    else
        silent = false;

    Session session(silent);

    int logged_in = 0;
    int shutdown = 0;
    string cmd;

    do {
        if (!silent)
            cout << ">>  xstream  <<" << endl;

        do {
            if (!silent)
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
