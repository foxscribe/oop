#include <cstdint>
#include <exception>
#include <print>
#include <string>
#include <string_view>

namespace
{
    inline constexpr int BITS              = 8;
    inline constexpr int REQUIRED_ARGS     = 2;
    inline constexpr int MIN               = 0;
    inline constexpr int MAX               = 256;
    inline constexpr std::string_view HELP = "Usage: {} <input byte>";
    inline constexpr std::string_view ERR  = "Error: Invalid value";
}

uint8_t Flip(uint8_t x)
{
    uint8_t result = 0;
    for (int i = BITS; i; i--) {
        result = (result << 1) | (x & 1);
        x >>= 1;
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != REQUIRED_ARGS)
    {
        std::println(HELP, argv[0]);
        return 0;
    }

    int byte;
    try
    {
        byte = std::stoi(std::string(argv[1]));
    }
    catch (std::exception _)
    {
        std::println(ERR);
        return 0;
    }
    if (byte >= MAX || byte < MIN)
    {
        std::println(ERR);
        return 0;
    }

    std::println("{}", Flip(byte));
    return 0;
}
