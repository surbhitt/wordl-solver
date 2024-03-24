#include <gtest/gtest.h>
#include "trial.cpp"

TEST(trial, trialsuite) {
    ASSERT_EQ(1, trial());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
