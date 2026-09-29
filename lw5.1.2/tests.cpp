#include "CVector3D.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <cmath>
#include <cfloat>

TEST(CVector3DTest, DefaultConstructor)
{
    CVector3D v;
    EXPECT_DOUBLE_EQ(v.x, 0.0);
    EXPECT_DOUBLE_EQ(v.y, 0.0);
    EXPECT_DOUBLE_EQ(v.z, 0.0);
}

TEST(CVector3DTest, ParameterizedConstructor)
{
    CVector3D v(1.5, -2.3, 4.7);
    EXPECT_DOUBLE_EQ(v.x, 1.5);
    EXPECT_DOUBLE_EQ(v.y, -2.3);
    EXPECT_DOUBLE_EQ(v.z, 4.7);
}

TEST(CVector3DTest, GetLengthZeroVector)
{
    CVector3D v(0, 0, 0);
    EXPECT_DOUBLE_EQ(v.GetLength(), 0.0);
}

TEST(CVector3DTest, GetLengthGeneralVector)
{
    CVector3D v(3, 4, 12);
    EXPECT_DOUBLE_EQ(v.GetLength(), 13.0);
}

TEST(CVector3DTest, NormalizeZeroVector)
{
    CVector3D v(0, 0, 0);
    v.Normalize();
    EXPECT_DOUBLE_EQ(v.x, 0.0);
    EXPECT_DOUBLE_EQ(v.y, 0.0);
    EXPECT_DOUBLE_EQ(v.z, 0.0);
}

TEST(CVector3DTest, NormalizeGeneralVector)
{
    CVector3D v(3, 4, 0);
    v.Normalize();
    EXPECT_DOUBLE_EQ(v.GetLength(), 1.0);
    EXPECT_DOUBLE_EQ(v.x, 0.6);
    EXPECT_DOUBLE_EQ(v.y, 0.8);
    EXPECT_DOUBLE_EQ(v.z, 0.0);
}

TEST(CVector3DTest, UnaryMinus)
{
    CVector3D v1(1.5, -2.3, 4.7);
    CVector3D v2 = -v1;
    EXPECT_DOUBLE_EQ(v2.x, -1.5);
    EXPECT_DOUBLE_EQ(v2.y, 2.3);
    EXPECT_DOUBLE_EQ(v2.z, -4.7);
}

TEST(CVector3DTest, Addition)
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    CVector3D result = v1 + v2;
    EXPECT_DOUBLE_EQ(result.x, 5.0);
    EXPECT_DOUBLE_EQ(result.y, 7.0);
    EXPECT_DOUBLE_EQ(result.z, 9.0);
}

TEST(CVector3DTest, Subtraction)
{
    CVector3D v1(4, 5, 6);
    CVector3D v2(1, 2, 3);
    CVector3D result = v1 - v2;
    EXPECT_DOUBLE_EQ(result.x, 3.0);
    EXPECT_DOUBLE_EQ(result.y, 3.0);
    EXPECT_DOUBLE_EQ(result.z, 3.0);
}

TEST(CVector3DTest, PlusEquals)
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    v1 += v2;
    EXPECT_DOUBLE_EQ(v1.x, 5.0);
    EXPECT_DOUBLE_EQ(v1.y, 7.0);
    EXPECT_DOUBLE_EQ(v1.z, 9.0);
}

TEST(CVector3DTest, MinusEquals)
{
    CVector3D v1(4, 5, 6);
    CVector3D v2(1, 2, 3);
    v1 -= v2;
    EXPECT_DOUBLE_EQ(v1.x, 3.0);
    EXPECT_DOUBLE_EQ(v1.y, 3.0);
    EXPECT_DOUBLE_EQ(v1.z, 3.0);
}

TEST(CVector3DTest, MultiplyByScalar)
{
    CVector3D v(1, 2, 3);
    CVector3D result = v * 2.0;
    EXPECT_DOUBLE_EQ(result.x, 2.0);
    EXPECT_DOUBLE_EQ(result.y, 4.0);
    EXPECT_DOUBLE_EQ(result.z, 6.0);
}

TEST(CVector3DTest, ScalarMultiplyVector)
{
    CVector3D v(1, 2, 3);
    CVector3D result = 2.0 * v;
    EXPECT_DOUBLE_EQ(result.x, 2.0);
    EXPECT_DOUBLE_EQ(result.y, 4.0);
    EXPECT_DOUBLE_EQ(result.z, 6.0);
}

TEST(CVector3DTest, DivideByScalar)
{
    CVector3D v(6, 8, 10);
    CVector3D result = v / 2.0;
    EXPECT_DOUBLE_EQ(result.x, 3.0);
    EXPECT_DOUBLE_EQ(result.y, 4.0);
    EXPECT_DOUBLE_EQ(result.z, 5.0);
}

TEST(CVector3DTest, EqualVectors)
{
    CVector3D v1(1.5, -2.3, 4.7);
    CVector3D v2(1.5, -2.3, 4.7);
    EXPECT_TRUE(v1 == v2);
    EXPECT_FALSE(v1 != v2);
}

TEST(CVector3DTest, NotEqualVectors)
{
    CVector3D v1(1.0, 2.0, 3.0);
    CVector3D v2(1.1, 2.0, 3.0);
    EXPECT_FALSE(v1 == v2);
    EXPECT_TRUE(v1 != v2);
}

TEST(CVector3DTest, OutputStreamOperator)
{
    CVector3D v(3, -2.5, 7);
    std::ostringstream oss;
    oss << v;
    EXPECT_EQ(oss.str(), "3, -2.5, 7");
}

TEST(CVector3DTest, InputStreamOperator)
{
    std::istringstream iss("3, -2.5, 7");
    CVector3D v;
    iss >> v;
    EXPECT_DOUBLE_EQ(v.x, 3.0);
    EXPECT_DOUBLE_EQ(v.y, -2.5);
    EXPECT_DOUBLE_EQ(v.z, 7.0);
}

TEST(CVector3DTest, DotProductOrthogonal)
{
    CVector3D v1(1, 0, 0);
    CVector3D v2(0, 1, 0);
    double result = DotProduct(v1, v2);
    EXPECT_DOUBLE_EQ(result, 0.0);
}

TEST(CVector3DTest, DotProductGeneral)
{
    CVector3D v1(1, -2, 3);
    CVector3D v2(-1, 2, -3);
    double result = DotProduct(v1, v2);
    EXPECT_DOUBLE_EQ(result, -14.0);
}

TEST(CVector3DTest, CrossProductStandardBasis)
{
    CVector3D v1(1, 0, 0);
    CVector3D v2(0, 1, 0);
    CVector3D result = CrossProduct(v1, v2);
    EXPECT_DOUBLE_EQ(result.x, 0.0);
    EXPECT_DOUBLE_EQ(result.y, 0.0);
    EXPECT_DOUBLE_EQ(result.z, 1.0);
}

TEST(CVector3DTest, CrossProductGeneralCase)
{
    CVector3D v1(1, 2, 3);
    CVector3D v2(4, 5, 6);
    CVector3D result = CrossProduct(v1, v2);
    EXPECT_DOUBLE_EQ(result.x, -3.0);
    EXPECT_DOUBLE_EQ(result.y, 6.0);
    EXPECT_DOUBLE_EQ(result.z, -3.0);
}

TEST(CVector3DTest, NormalizeFunctionGeneralVector)
{
    CVector3D v(3, 4, 0);
    CVector3D result = Normalize(v);
    EXPECT_DOUBLE_EQ(result.GetLength(), 1.0);
    EXPECT_DOUBLE_EQ(result.x, 0.6);
    EXPECT_DOUBLE_EQ(result.y, 0.8);
    EXPECT_DOUBLE_EQ(result.z, 0.0);
}

TEST(CVector3DTest, NormalizeFunctionZeroVector)
{
    CVector3D v(0, 0, 0);
    CVector3D result = Normalize(v);
    EXPECT_DOUBLE_EQ(result.x, 0.0);
    EXPECT_DOUBLE_EQ(result.y, 0.0);
    EXPECT_DOUBLE_EQ(result.z, 0.0);
}

TEST(CVector3DTest, NormalizeFunctionDoesNotModifyOriginal)
{
    CVector3D v(3, 4, 0);
    CVector3D original = v;
    CVector3D result = Normalize(v);

    EXPECT_DOUBLE_EQ(v.x, original.x);
    EXPECT_DOUBLE_EQ(v.y, original.y);
    EXPECT_DOUBLE_EQ(v.z, original.z);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
