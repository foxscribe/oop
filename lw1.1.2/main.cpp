#include <cstdlib>
#include <fstream>
#include <print>
#include <string>
#include <utility>

std::pair<bool, int> compare(std::string first_filename, std::string second_filename)
{
    std::ifstream first_file(first_filename);
    if (!first_file.is_open())
    {
        std::println("Error: File {} does not exist", first_filename);
        std::exit(3);
    }
    std::ifstream second_file(second_filename);
    if (!second_file.is_open())
    {
        std::println("Error: File {} does not exist", second_filename);
        std::exit(3);
    }

    int line = 1;
    std::string line_first, line_second;
    while (std::getline(first_file, line_first) && std::getline(second_file, line_second))
    {
        if (line_first.compare(line_second) != 0)
        {
            return std::pair(false, line);
        }
        line++;
    }

    if (std::getline(first_file, line_first) || std::getline(second_file, line_second))
    {
        return std::pair(false, line + 1);
    }

    return std::pair(true, 0);
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::println("Error: Not enough or too much arguments. Usage: {} <file1> <file2>", argv[0]);
        return 2;
    }

    std::string first_filename(argv[1]);
    std::string second_filename(argv[2]);
    if (first_filename.compare(second_filename) == 0)
    {
        std::println("Error: Given the same file twice");
        return 4;
    }

    auto result = compare(first_filename, second_filename);
    if (result.first)
    {
        std::println("Files are equal");
        return 0;
    }
    else
    {
        std::println("Files are different. Line number is {}", result.second);
        return 1;
    }
}
