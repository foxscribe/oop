#include <gtest/gtest.h>
#include <numbers>
#include "../include/CCircle.hpp"

TEST(CCircleTest, GetCenter_ReturnsCorrectPoint)
{
    CCircle circle({1.0, 2.0}, 5.0, 0xFF0000, 0x00FF00);
    CPoint expected{1.0, 2.0};
    EXPECT_EQ(circle.GetCenter(), expected);
}

TEST(CCircleTest, GetRadius_ReturnsCorrectRadius)
{
    CCircle circle({1.0, 2.0}, 5.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(circle.GetRadius(), 5.0);
}

TEST(CCircleTest, GetOutlineColor_ReturnsCorrectColor)
{
    CCircle circle({1.0, 2.0}, 5.0, 0xFF0000, 0x00FF00);
    EXPECT_EQ(circle.GetOutlineColor(), 0xFF0000u);
}

TEST(CCircleTest, GetFillColor_ReturnsCorrectColor)
{
    CCircle circle({1.0, 2.0}, 5.0, 0xFF0000, 0x00FF00);
    EXPECT_EQ(circle.GetFillColor(), 0x00FF00u);
}

TEST(CCircleTest, GetArea_ReturnsCorrectArea)
{
    CCircle circle({0.0, 0.0}, 2.0, 0xFF0000, 0x00FF00);
    double expectedArea = std::numbers::pi * 2.0 * 2.0;
    EXPECT_DOUBLE_EQ(circle.GetArea(), expectedArea);
}

TEST(CCircleTest, GetPerimeter_ReturnsCorrectPerimeter)
{
    CCircle circle({0.0, 0.0}, 2.0, 0xFF0000, 0x00FF00);
    double expectedPerimeter = 2.0 * std::numbers::pi * 2.0;
    EXPECT_DOUBLE_EQ(circle.GetPerimeter(), expectedPerimeter);
}
