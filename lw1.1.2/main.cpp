#include <cstdlib>
#include <fstream>
#include <print>
#include <string>
#include <utility>

std::pair<bool, int> Compare(std::string firstFilename, std::string secondFilename)
{
    std::ifstream firstFile(firstFilename);
    if (!firstFile.is_open())
    {
        std::println("Error: File {} does not exist", firstFilename);
        std::exit(3);
    }
    std::ifstream secondFile(secondFilename);
    if (!secondFile.is_open())
    {
        std::println("Error: File {} does not exist", secondFilename);
        std::exit(3);
    }

    int lineNumber = 1;
    std::string lineFirst, lineSecond;
    while (std::getline(firstFile, lineFirst) && std::getline(secondFile, lineSecond))
    {
        if (lineFirst.compare(lineSecond) != 0)
        {
            return std::pair(false, lineNumber);
        }
        lineNumber++;
    }

    if (std::getline(firstFile, lineFirst) || std::getline(secondFile, lineSecond))
    {
        return std::pair(false, lineNumber);
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

    std::string firstFilename(argv[1]);
    std::string secondFilename(argv[2]);
    if (firstFilename.compare(secondFilename) == 0)
    {
        std::println("Error: Given the same file twice");
        return 4;
    }

    auto result = Compare(firstFilename, secondFilename);
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
