#include <iostream>
#include <print>
#include <string>
#include "solution.hpp"

int main()
{
    std::string input;
    while (true)
    {
        std::getline(std::cin, input);
        std::println("{}", TrimBlanks(input));
    }
}
