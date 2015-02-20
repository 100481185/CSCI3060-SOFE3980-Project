#include <iostream>
#include "xstream.h"

int main(int argc, char **argv) {

    using namespace std;

    cout << "Xstream" << endl;


    cout << "Enter your command: " << endl;
    string cmd;
    cin >> cmd;

    int check;

    check = cmdFilter(cmd, loggedIn);

    switch (check) {
        case 0:
            check = login();
            break;
        case 1:
            break;
        default:
            break;
    }

    return check;

}







