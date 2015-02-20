#include "cmdfilter.h"

int cmdFilter(string cmd, bool loggedIn) {
    if ((cmd == "login") && (!loggedIn)) {
        return 0;
    } else {
        return -1;
    }
}