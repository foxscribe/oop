#include <gtest/gtest.h>
#include <set>
#include "solution.hpp"

TEST(SolutionTest, EmptySets)
{
    EXPECT_EQ(CrossSet(std::set<int>{}, std::set<int>{}), std::set<int>{});
}

TEST(SolutionTest, NoIntersect)
{
    EXPECT_EQ(CrossSet(std::set<int>{2, 4}, std::set<int>{1, 3}), std::set<int>{});
}

TEST(SolutionTest, OneIntersect)
{
    EXPECT_EQ(CrossSet(std::set<int>{2, 4}, std::set<int>{2, 3}), std::set<int>{2});
}

TEST(SolutionTest, ManyIntersect)
{
    EXPECT_EQ(CrossSet(std::set<int>{2, 4, 5}, std::set<int>{2, 3, 5}), (std::set<int>{2, 5}));
}
