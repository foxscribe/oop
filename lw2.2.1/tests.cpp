#include <gtest/gtest.h>
#include "solution.hpp"

TEST(SolutionTest, BlankString)
{
    EXPECT_EQ(TrimBlanks(""), "");
}

TEST(SolutionTest, AllSpaces)
{
    EXPECT_EQ(TrimBlanks("   "), "");
}

TEST(SolutionTest, NoSpaces)
{
    EXPECT_EQ(TrimBlanks("Test  sentence"), "Test  sentence");
}

TEST(SolutionTest, OneSideOneSpace)
{
    EXPECT_EQ(TrimBlanks(" Test  sentence"), "Test  sentence");
}

TEST(SolutionTest, TwoSidesOneSpace)
{
    EXPECT_EQ(TrimBlanks(" Test  sentence "), "Test  sentence");
}

TEST(SolutionTest, OneSideManySpaces)
{
    EXPECT_EQ(TrimBlanks("    Test  sentence"), "Test  sentence");
}

TEST(SolutionTest, TwoSidesManySpaces)
{
    EXPECT_EQ(TrimBlanks("   Test  sentence  "), "Test  sentence");
}
