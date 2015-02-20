#ifndef XSTREAM_TEST_LOGINTESTSUITE_H
#define XSTREAM_TEST_LOGINTESTSUITE_H

#include <gtest/gtest.h>
#include "./../control.h"
#include "./../login.h"


// Tests if 'login' will return 0
TEST(LoginTestCase, invalidReadFileTest) {
    ASSERT_EQ(readFile(USERACCNT), 0);

//    ASSERT_LT(cmdFilter(" "), 0);
//    ASSERT_LT(cmdFilter("Login"), 0);
}

//Test(ControlTestCase, ) {
//    ASSERT_EQ(login(&loggedIn), 0);
//}


#endif