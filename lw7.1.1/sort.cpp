#include "sort.hpp"
#include <cstring>

template <>
void Sort2<const char*>(const char* & first, const char* & second)
{
    if (std::strcmp(first, second) > 0)
    {
        const char* buffer = first;
        first = second;
        second = buffer;
    }
}
