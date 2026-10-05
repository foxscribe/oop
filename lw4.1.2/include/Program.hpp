#include "CShapeParser.hpp"
#include "IShape.hpp"
#include <istream>
#include <memory>
#include <ostream>
#include <vector>

class Program
{
public:
    Program(std::istream& in, std::ostream& out);

    void Run();

private:
    IShape* FindLargestArea();
    IShape* FindSmallestPerimeter();

    std::vector<std::unique_ptr<IShape>> m_shapes;
    CShapeParser m_parser;
    std::istream& m_in;
    std::ostream& m_out;
};
