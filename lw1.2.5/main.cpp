#include <cstdint>
#include <exception>
#include <print>
#include <string>

uint8_t Flip(uint8_t x)
{
    uint8_t result = 0;
    for (int i = 8; i; i--) {
        result = (result << 1) | (x & 1);
        x >>= 1;
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::println("Usage: {} <input byte>", argv[0]);
        return 0;
    }

    int byte;
    try
    {
        byte = std::stoi(std::string(argv[1]));
    }
    catch (std::exception _)
    {
        std::println("Error: Invalid value");
        return 0;
    }
    if (byte > 255 || byte < 0)
    {
        std::println("Error: Invalid value");
        return 0;
    }

    std::println("{}", Flip(byte));
    return 0;
}
