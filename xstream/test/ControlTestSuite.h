#include <gtest/gtest.h>
#include "../src/controller/control.h"


// Tests if 'login' will return 0
TEST(CMDFilterTestCase, InputLogin) {
    ASSERT_EQ(cmdManager("login"), 0);
    ASSERT_LT(cmdManager(" "), 0);
    ASSERT_LT(cmdManager("Login"), 0);
}

//Test(ControlTestCase, ) {
//    ASSERT_ANY_THROW(<#statement#>);
//}

