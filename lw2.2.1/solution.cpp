#include "solution.hpp"

#include <cstddef>
#include <cstdio>
#include <string>

namespace
{
    inline constexpr char TARGET       = ' ';
    inline constexpr std::string BLANK = "";
}

std::string TrimBlanks(std::string const& str)
{
    std::string result = str;
    std::size_t start = result.find_first_not_of(TARGET);
    std::size_t end = result.find_last_not_of(TARGET);
    if (start == std::string::npos || end == std::string::npos)
    {
        return BLANK;
    }
    return result.substr(start, end - start + 1);
}
