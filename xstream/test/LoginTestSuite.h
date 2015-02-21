#ifndef XSTREAM_TEST_LOGINTESTSUITE_H
#define XSTREAM_TEST_LOGINTESTSUITE_H

#include <gtest/gtest.h>
#include "../src/login/login.h"
#include "../src/data/user/account.h"

#include <exception>


// OpenFile Test Case
TEST(LoginTestSuite, openFileTestCase) {

    EXPECT_NO_FATAL_FAILURE(openFile("xstream/data/UserAccounts.txt"))
                        << "The UsrAcnt.txt was not opened \n"
                                "This was done purposly.";

    ASSERT_EQ(openFile(USERACCOUNT_TXT), 0)
    <<  "The UsrAcnt.txt was not opened \n"
            "This must not happen.";

}

// Read file Test Case
TEST(LoginTestSuite, readFileTestCase) {
    ifstream testFile;
    ASSERT_EQ((readFile(&testFile)), 0)
    << "The file is not being read";


    testFile.open(USERACCOUNT_TXT);
    ASSERT_TRUE(testFile.is_open());
    ASSERT_EQ((readFile(&testFile)), 0)
    << "The file is not being read";
}

TEST(LoginTestSuite, storeDataTestCase) {
    ASSERT_EQ(openFile(USERACCOUNT_TXT), 0);
//    printf("%i ", accounts.size());
    ASSERT_TRUE(accounts.size());
}

TEST(LoginTestSuite, sendNameTestCase) {
    bool loggedIn = false;
    string permission = "";
    ASSERT_EQ(openFile(USERACCOUNT_TXT), 0);
    ASSERT_TRUE(checkUser("User1", &loggedIn, &permission));
}

TEST(LoginTestSuite, loginMainTestCase) {

}

#endif