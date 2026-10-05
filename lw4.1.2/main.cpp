#include "include/Program.hpp"
#include <exception>
#include <iostream>

int main()
{
    Program program(std::cin, std::cout);
    try
    {
        program.Run();
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
