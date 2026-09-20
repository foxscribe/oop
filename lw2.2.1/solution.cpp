#include "solution.hpp"

#include <cstddef>
#include <cstdio>
#include <string>

std::string TrimBlanks(std::string const& str)
{
    std::string result = str;
    std::size_t start = result.find_first_not_of(' ');
    std::size_t end = result.find_last_not_of(' ');
    if (start == std::string::npos || end == std::string::npos)
    {
        return "";
    }
    return result.substr(start, end - start + 1);
}
