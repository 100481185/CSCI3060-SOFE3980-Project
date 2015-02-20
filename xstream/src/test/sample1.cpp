#include <gtest/gtest.h>
#include "./../control.h"


TEST(MainProgramTest, PositiveNos) {
    ASSERT_EQ(0, cmdFilter(("login")));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}