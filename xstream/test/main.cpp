#include "LoginTestSuite.h"

using namespace std;


#define LOGIN        'l'
#define LOGOUT       'q'
#define CREATE       'c'
#define DELETE       'd'
#define SELL         's'
#define BUY          'b'
#define REFUND       'r'
#define ADDCREDIT    'a'


int main(int argc, char **argv) {
    if (argc == 1) {
        cout << "Running full Test Suite" << endl;
    } else if (argc <= 2) {
        cout << "life" << argv[1] << endl;
        switch ((int) *argv[1]) {
            case LOGIN:
                ::testing::FLAGS_gtest_filter = "LoginTestSuite";
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

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}