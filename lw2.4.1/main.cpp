#include <exception>
#include <print>
#include <set>
#include <string>
#include <iostream>
#include <cstdlib>
#include "solution.hpp"

#define ERROR "ERROR"

void ShowHelp()
{
    std::println("Usage: program [N]");
    std::println("  N - positive integer");
    std::println("  If N is not provided, it will be read from stdin");
    std::println("  -h - show this help");
}

int SumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void PrintSet(const std::set<int>& s)
{
    bool first = true;
    for (int x : s)
    {
        if (!first)
        {
            std::print(" ");
        }
        std::print("{}", x);
        first = false;
    }
    std::println();
}

int main(int argc, char* argv[])
{
    int n = 0;
    if (argc > 1)
    {
        std::string arg = argv[1];
        if (arg == "-h")
        {
            ShowHelp();
            return 0;
        }

        try
        {
            size_t pos;
            n = std::stoi(arg, &pos);
            if (pos != arg.length() || n <= 0)
            {
                std::println(ERROR);
                return 1;
            }
        }
        catch (std::exception _)
        {
            std::println(ERROR);
            return 1;
        }
    }
    else
    {
        if (!(std::cin >> n) || n <= 0)
        {
            std::println(ERROR);
            return 0;
        }
    }

    std::set<int> set1, set2;

    for (int i = 1; i <= n; ++i)
    {
        int digitSum = SumOfDigits(i);
        if (digitSum > 0 && i % digitSum == 0)
        {
            set1.insert(i);
        }
        if (digitSum % 2 == 0)
        {
            set2.insert(i);
        }
    }

    std::set<int> intersection = CrossSet(set1, set2);

    PrintSet(set1);
    PrintSet(set2);
    PrintSet(intersection);

    return 0;
}
