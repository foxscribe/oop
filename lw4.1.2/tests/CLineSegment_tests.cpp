#include <gtest/gtest.h>
#include "../include/CLineSegment.hpp"

TEST(CLineSegmentTest, GetStartPoint_ReturnsCorrectPoint)
{
    CLineSegment segment({0.0, 0.0}, {3.0, 4.0}, 0xFF0000);
    CPoint expected{0.0, 0.0};
    EXPECT_EQ(segment.GetStartPoint(), expected);
}

TEST(CLineSegmentTest, GetEndPoint_ReturnsCorrectPoint)
{
    CLineSegment segment({0.0, 0.0}, {3.0, 4.0}, 0xFF0000);
    CPoint expected{3.0, 4.0};
    EXPECT_EQ(segment.GetEndPoint(), expected);
}

TEST(CLineSegmentTest, GetOutlineColor_ReturnsCorrectColor)
{
    CLineSegment segment({0.0, 0.0}, {3.0, 4.0}, 0xFF0000);
    EXPECT_EQ(segment.GetOutlineColor(), 0xFF0000u);
}

TEST(CLineSegmentTest, GetArea_ReturnsZero)
{
    CLineSegment segment({0.0, 0.0}, {3.0, 4.0}, 0xFF0000);
    EXPECT_DOUBLE_EQ(segment.GetArea(), 0.0);
}

TEST(CLineSegmentTest, GetPerimeter_ReturnsCorrectLength)
{
    CLineSegment segment({0.0, 0.0}, {3.0, 4.0}, 0xFF0000);
    EXPECT_DOUBLE_EQ(segment.GetPerimeter(), 5.0);
}
