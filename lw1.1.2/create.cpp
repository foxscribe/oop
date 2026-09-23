#include<fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return 0;
    }

    std::ofstream out(std::string{argv[1]});
    out << "\r\n";
}
