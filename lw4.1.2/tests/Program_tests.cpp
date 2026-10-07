#include <gtest/gtest.h>
#include <sstream>
#include "../include/Program.hpp"

namespace
{
    inline constexpr auto INPUT =
        "rectangle 0 0 20 20 9B9B9BFF 9B9B9BFF\n"
        "rectangle 0 0 40 40 9B9B9BFF 9B9B9BFF\n"
        "rectangle 0 0 60 60 9B9B9BFF 9B9B9BFF\n";
}

TEST(ProgramTest, FindsCorrectShapes)
{
    std::istringstream in(INPUT);
    std::ostringstream out;
    Program program(in, out);
    program.Run();

    auto area = program.FindLargestArea();
    auto perimeter = program.FindSmallestPerimeter();

    EXPECT_EQ(area->GetArea(), 3600);
    EXPECT_EQ(perimeter->GetPerimeter(), 80);
}
