#include <gtest/gtest.h>
#include <format>
#include "../include/CPoint.hpp"

TEST(CPointTest, EqualityOperator_ReturnsTrue_ForIdenticalPoints)
{
    CPoint p1{1.0, 2.0};
    CPoint p2{1.0, 2.0};
    EXPECT_TRUE(p1 == p2);
}

TEST(CPointTest, EqualityOperator_ReturnsFalse_ForDifferentPoints)
{
    CPoint p1{1.0, 2.0};
    CPoint p2{1.0, 3.0};
    EXPECT_FALSE(p1 == p2);
}

TEST(CPointTest, InequalityOperator_ReturnsTrue_ForDifferentPoints)
{
    CPoint p1{1.0, 2.0};
    CPoint p2{3.0, 2.0};
    EXPECT_TRUE(p1 != p2);
}

TEST(CPointTest, InequalityOperator_ReturnsFalse_ForIdenticalPoints)
{
    CPoint p1{1.0, 2.0};
    CPoint p2{1.0, 2.0};
    EXPECT_FALSE(p1 != p2);
}

TEST(CPointTest, Distance_ReturnsCorrectValue)
{
    CPoint p1{0.0, 0.0};
    CPoint p2{3.0, 4.0};
    EXPECT_DOUBLE_EQ(p1.Distance(p2), 5.0);
}

TEST(CPointTest, Format_ReturnsCorrectString)
{
    CPoint p{1.5, 2.5};
    std::string result = std::format("{}", p);
    EXPECT_EQ(result, "(1.5, 2.5)");
}
