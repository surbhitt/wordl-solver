#include "solver.cpp"
#include <gtest/gtest.h>

void exp_loop(validity p[5], validity expected[5]) {
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(p[i], expected[i]);
}

class Wordl_Test : public testing::Test {
    protected:
        Wordl w_obj;
        Wordl_Test(): w_obj("hello") {};
        // void SetUp() override { 
        //     w_obj = Wordl("hello"); 
        // } 
};

TEST_F(Wordl_Test, CheckAllMatch) {
    validity expected[5] = {MATCH, MATCH, MATCH, MATCH, MATCH};
    validity pat[5];
    w_obj.check("bello", "bello", pat);
    exp_loop(pat, expected);
}

TEST_F(Wordl_Test, Check1Mp1Nm) {
    validity expected[5] = {MISPLACED, NOMATCH, MATCH, MATCH, MATCH};
    validity pat[5];
    w_obj.check("bello", "hbllo", pat);
    exp_loop(pat, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
