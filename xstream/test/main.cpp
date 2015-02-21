#include "XStreamTestSuite.h"

using namespace std;

int main(int argc, char **argv) {

    if (argc == 1) {
        cout << "Running full Test Suite" << endl;
    } else if (argc <= 2) {
        switch (atoi(argv[1])) {
            case LOGIN:
                testing::FLAGS_gtest_filter = "LoginTestSuite.*";
                break;
            case LOGOUT:
            case CREATE:
            case DELETE:
            case SELL:
            case BUY:
            case REFUND:
            case ADDCREDIT:
            default:
                break;
        }
    }
    testing::FLAGS_gtest_color = "auto";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}