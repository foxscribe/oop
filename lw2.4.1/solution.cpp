#include "solution.hpp"

#include <algorithm>

std::set<int> CrossSet(std::set<int> const& set1, std::set<int> const& set2)
{
    std::set<int> result{};
    std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                              std::inserter(result, result.end()));
    return result;
}
