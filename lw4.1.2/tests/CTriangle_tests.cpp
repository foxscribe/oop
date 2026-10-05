#include <gtest/gtest.h>
#include "../include/CTriangle.hpp"

TEST(CTriangleTest, GetVertex1_ReturnsCorrectPoint)
{
    CTriangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    CPoint expected{0.0, 0.0};
    EXPECT_EQ(triangle.GetVertex1(), expected);
}

TEST(CTriangleTest, GetVertex2_ReturnsCorrectPoint)
{
    CTriangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    CPoint expected{4.0, 0.0};
    EXPECT_EQ(triangle.GetVertex2(), expected);
}

TEST(CTriangleTest, GetVertex3_ReturnsCorrectPoint)
{
    CTriangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    CPoint expected{0.0, 3.0};
    EXPECT_EQ(triangle.GetVertex3(), expected);
}

TEST(CTriangleTest, GetOutlineColor_ReturnsCorrectColor)
{
    CTriangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    EXPECT_EQ(triangle.GetOutlineColor(), 0xFF0000u);
}

TEST(CTriangleTest, GetFillColor_ReturnsCorrectColor)
{
    CTriangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    EXPECT_EQ(triangle.GetFillColor(), 0x00FF00u);
}

TEST(CTriangleTest, GetArea_ReturnsCorrectArea)
{
    CTriangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(triangle.GetArea(), 6.0);
}

TEST(CTriangleTest, GetArea_ReturnsZero)
{
    CTriangle triangle({0.0, 0.0}, {2.0, 0.0}, {4.0, 0.0}, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(triangle.GetArea(), 0.0);
}

TEST(CTriangleTest, GetPerimeter_ReturnsCorrectPerimeter)
{
    CTriangle triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(triangle.GetPerimeter(), 12.0);
}
