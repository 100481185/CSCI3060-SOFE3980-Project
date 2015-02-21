#ifndef XSTREAM_TEST_LOGINTESTSUITE_H
#define XSTREAM_TEST_LOGINTESTSUITE_H

#include <gtest/gtest.h>
#include "../src/login/login.h"
#include "../src/data/user/account.h"
#include "../src/logout/logout.h"

#include <exception>

// TODO: make class

class UserAccountTest : public ::testing::Test
{
protected:
    virtual void SetUp() {
        loggedIn_ = true;
        permission_ = '';
        ifstream fd;
        fd.open(USERACCOUNT_TXT);
        if (fd.is_open()) {
            ptr = accounts.begin();
            std::string line;
            while (getline(fd, line)) {
                try {
                    accounts.insert(ptr, loadData(line));
                } catch (exception &e) {
                    e.what();
                    fd.close();
                }
            }
            fd.close();
        }
    }

    virtual void TearDown() {
        for (ptr = accounts.begin(); ptr != accounts.end(); ptr++) {
            accounts.erase(ptr);
        }
    }


    bool loggedIn_;
    string permission_;

};


TEST_F(UserAccountTest, AuthWorks) {
    int check = checkUser("User1", &loggedIn_, &permission_);
    ASSERT_EQ(check, 0);
}



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
//    ASSERT_TRUE(accounts.size());
}

TEST(LoginTestSuite, sendNameTestCase) {
    bool loggedIn = false;
    string permission = "";


    ASSERT_FALSE(checkUser("User1", &loggedIn, &permission));
    ASSERT_TRUE(loggedIn);
    ASSERT_EQ(permission, "AA");


}


TEST(LoginTestSuite, loginMainTestCase) {

}

#endif