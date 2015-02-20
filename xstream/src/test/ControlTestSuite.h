#include <gtest/gtest.h>
#include "./../control.h"


// Tests if 'login' will return 0
TEST(CMDFilterTestCase, InputLogin) {
    ASSERT_EQ(cmdFilter("login"), 0);
    ASSERT_LT(cmdFilter(" "), 0);
    ASSERT_LT(cmdFilter("Login"), 0);
}

//Test(ControlTestCase, ) {
//    ASSERT_ANY_THROW(<#statement#>);
//}

