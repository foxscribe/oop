#include <gtest/gtest.h>
#include "../include/CRectangle.hpp"

TEST(CRectangleTest, GetLeftTop_ReturnsCorrectPoint)
{
    CRectangle rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    CPoint expected{1.0, 2.0};
    EXPECT_EQ(rect.GetLeftTop(), expected);
}

TEST(CRectangleTest, GetRightBottom_ReturnsCorrectPoint)
{
    CRectangle rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    CPoint expected{4.0, 6.0};
    EXPECT_EQ(rect.GetRightBottom(), expected);
}

TEST(CRectangleTest, GetWidth_ReturnsCorrectWidth)
{
    CRectangle rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(rect.GetWidth(), 3.0);
}

TEST(CRectangleTest, GetHeight_ReturnsCorrectHeight)
{
    CRectangle rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(rect.GetHeight(), 4.0);
}

TEST(CRectangleTest, GetOutlineColor_ReturnsCorrectColor)
{
    CRectangle rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_EQ(rect.GetOutlineColor(), 0xFF0000u);
}

TEST(CRectangleTest, GetFillColor_ReturnsCorrectColor)
{
    CRectangle rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_EQ(rect.GetFillColor(), 0x00FF00u);
}

TEST(CRectangleTest, GetArea_ReturnsCorrectArea)
{
    CRectangle rect({0.0, 0.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(rect.GetArea(), 12.0);
}

TEST(CRectangleTest, GetPerimeter_ReturnsCorrectPerimeter)
{
    CRectangle rect({0.0, 0.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(rect.GetPerimeter(), 14.0);
}
