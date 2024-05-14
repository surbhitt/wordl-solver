#include "../solver.cpp"
#include <gtest/gtest.h>

void exp_loop(validity p[5], validity expected[5]) {
    for (int i = 0; i < 5; i++)
        EXPECT_EQ(p[i], expected[i]);
}

class Wordl_Test : public testing::Test {
  protected:
    Wordl w_obj;
    Wordl_Test() : w_obj("hello"){};
};

TEST_F(Wordl_Test, CheckAllMatch) {
    validity expected[5] = {MATCH, MATCH, MATCH, MATCH, MATCH};
    validity pat[5];
    w_obj.check("abcde", "abcde", pat);
    exp_loop(pat, expected);
}

TEST_F(Wordl_Test, CheckOneNomatch) {
    validity expected[5] = {MATCH, MATCH, MATCH, MATCH, NOMATCH};
    validity pat[5];
    w_obj.check("abcdf", "abcde", pat);
    exp_loop(pat, expected);
}

TEST_F(Wordl_Test, CheckAllNomatch) {
    validity expected[5] = {NOMATCH, NOMATCH, NOMATCH, NOMATCH, NOMATCH};
    validity pat[5];
    w_obj.check("abcde", "fghij", pat);
    exp_loop(pat, expected);
}

TEST_F(Wordl_Test, CheckAllMisplaced) {
    validity expected[5] = {MISPLACED, MISPLACED, MISPLACED, MISPLACED,
                            MISPLACED};
    validity pat[5];
    w_obj.check("abcde", "eabcd", pat);
    exp_loop(pat, expected);
}

TEST_F(Wordl_Test, Check1Mp1M) {
    validity expected[5] = {MISPLACED, MATCH, NOMATCH, NOMATCH, NOMATCH};
    validity pat[5];
    w_obj.check("baaaa", "aaccc", pat);
    exp_loop(pat, expected);
}

TEST_F(Wordl_Test, Check1Mp1Nm) {
    validity expected[5] = {MATCH, MATCH, MATCH, MISPLACED, NOMATCH};
    validity pat[5];
    w_obj.check("aaaab", "aaabc", pat);
    exp_loop(pat, expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
check!("abcde" + [C C C C C] allows "abcde");
check!("abcdf" + [C C C C C] disallows "abcde");
check!("abcde" + [W W W W W] allows "fghij");
check!("abcde" + [M M M M M] allows "eabcd");
check!("baaaa" + [W C M W W] allows "aaccc");
check!("baaaa" + [W C M W W] disallows "caacc");
check!("tares" + [W M M W W] disallows "brink");
check!("aaaab" + [C C C W M] allows "aaabc");
check!("aaabc" + [C C C M W] allows "aaaab");
check!("aaabb" + [C M W W W] disallows "accaa");
check!("abcde" + [W W W W W] disallows "bcdea");
*/
