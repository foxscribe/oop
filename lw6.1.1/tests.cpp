#include <gtest/gtest.h>
#include "solution.hpp"

TEST(EquationRootsTest, EqualityZeroRoots) {
    EquationRoots a{0, {0.0, 0.0}};
    EquationRoots b{0, {99.9, -5.5}};
    EXPECT_EQ(a, b);
}

TEST(EquationRootsTest, EqualityOneRoot) {
    EquationRoots a{1, {5.0, 0.0}};
    EquationRoots b{1, {5.0, 99.0}};
    EXPECT_EQ(a, b);

    EquationRoots c{1, {5.1, 0.0}};
    EXPECT_NE(a, c);
}

TEST(EquationRootsTest, EqualityTwoRoots) {
    EquationRoots a{2, {1.5, 2.5}};
    EquationRoots b{2, {1.5, 2.5}};
    EXPECT_EQ(a, b);

    EquationRoots c{2, {1.5, 3.5}};
    EXPECT_NE(a, c);

    EquationRoots d{2, {2.5, 1.5}};
    EXPECT_NE(a, d);
}

TEST(EquationRootsTest, InequalityDifferentNumRoots) {
    EquationRoots a{0, {}};
    EquationRoots b{1, {1.0, 0.0}};
    EquationRoots c{2, {1.0, 2.0}};

    EXPECT_NE(a, b);
    EXPECT_NE(b, c);
    EXPECT_NE(a, c);
}

TEST(EquationRootsTest, OutputStreamZeroRoots) {
    EquationRoots r{0, {}};
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "(none)");
}

TEST(EquationRootsTest, OutputStreamOneRoot) {
    EquationRoots r{1, {3.14, 0.0}};
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "(3.14)");
}

TEST(EquationRootsTest, OutputStreamTwoRoots) {
    EquationRoots r{2, {1.5, -2.5}};
    std::ostringstream oss;
    oss << r;
    EXPECT_EQ(oss.str(), "(1.5, -2.5)");
}

TEST(SolveTest, AIsZero)
{
    EXPECT_THROW(Solve(0.0, 5.0, 6.0), std::invalid_argument);
}

TEST(SolveTest, NoRealRoots)
{
    // x^2 + 1 = 0 -> D = -4
    EXPECT_THROW(Solve(1.0, 0.0, 1.0), std::domain_error);
}

TEST(SolveTest, OneRoot)
{
    // x^2 - 2x + 1 = 0 -> (x - 1)^2 = 0 -> x = 1
    EquationRoots expected{1, {1.0, 0.0}};
    EXPECT_EQ(Solve(1.0, -2.0, 1.0), expected);
}

TEST(SolveTest, TwoRoots)
{
    // x^2 - 3x + 2 = 0 -> корни 1 и 2
    EquationRoots expected{2, {1.0, 2.0}};
    EXPECT_EQ(Solve(1.0, -3.0, 2.0), expected);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
