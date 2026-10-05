#include <exception>
#include <iostream>
#include <string_view>
#include "solution.hpp"

namespace
{
    inline constexpr std::string_view INPUT_PROMPT  = "Enter the coefficients: ";
    inline constexpr std::string_view RESULT_PREFIX = "Result: ";
}

int main()
{
    double a, b, c;
    std::cout << INPUT_PROMPT;
    std::cin >> a >> b >> c;

    try
    {
        auto roots = Solve(a, b, c);
        std::cout << RESULT_PREFIX << roots << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
