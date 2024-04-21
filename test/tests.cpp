// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "Markov.h"

TEST(test1, 1Test) {
    std::vector<std::string>words{ "a", "b", "c"};
    MarkovChain mark;
    std::deque<std::string> prefix;
    prefix.push_back("a");
    prefix.push_back("b");
    mark.CreateStatetab(words, 2);
    EXPECT_EQ(prefix, mark.firstPref);
}

TEST(test2, 2Test) {
    std::vector<std::string>words{ "a", "b", "c"};
    MarkovChain mark;
    std::deque<std::string> prefix{ "a", "b" };
    mark.CreateStatetab(words, 2);
    std::vector<std::string> suffix{ "3" };
    EXPECT_EQ(mark.statetab.begin()->second, suffix);
}

TEST(test3, 2Test) {
    std::vector<std::string>words{ "a", "b", "3", "4", "c" };
    MarkovChain mark;
    mark.CreateStatetab(words, 1);
    EXPECT_EQ(mark.CreateText(10, 10), "a b 3 4 c ");
}

TEST(test4, 3Test) {
    std::vector<std::string>words{ "1",
    "2", "3", "4", "5",
    "2", "3", "1", "2", "4", 
    "5", "1"};
    MarkovChain mark;
    mark.CreateStatetab(words, 1);
    EXPECT_EQ(mark.CreateText(10, 10), "1 2 4 5 2 4 5 1 2 3 ");
}

TEST(test5, F4Test) {
    typedef std::deque<std::string> prefix;
    std::map<prefix, std::vector<std::string> > state = {
        { { "two" }, { "OnE23", "oNe" } },
        { { "one11" }, { "tWo", "TwO1" } },
        { {"three2"}, {"tree"} }
    };
    MarkovChain mark;
    typedef std::deque<std::string> prefix;
    prefix pre{ "one" };
    mark.statetab = state;
    mark.firstPref = pre;
    EXPECT_EQ(mark.CreateText(10, 10), "one11 TwO1 ");
}
