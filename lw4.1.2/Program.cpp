#include "include/Program.hpp"
#include "include/IShape.hpp"

#include <algorithm>
#include <ranges>
#include <stdexcept>

namespace Errors
{
    inline constexpr auto NO_SHAPES = "no shapes available";
}

namespace Messages
{
    inline constexpr auto MAX_AREA = "Shape with the largest area:\n";
    inline constexpr auto MIN_PERIMETER = "Shape with the smallest perimeter:\n";
}

Program::Program(std::istream& in, std::ostream& out)
    : m_in(in), m_out(out)
{
}

void Program::Run()
{
    m_parser.Parse(m_in, m_shapes);
    auto areaShape = FindLargestArea();
    auto perimeterShape = FindSmallestPerimeter();
    m_out << Messages::MAX_AREA << areaShape->ToString() << '\n';
    m_out << Messages::MIN_PERIMETER << perimeterShape->ToString() << '\n';
}

IShape* Program::FindLargestArea()
{
	if (std::ranges::begin(m_shapes) == std::ranges::end(m_shapes))
	{
		throw std::runtime_error(Errors::NO_SHAPES);
	}

	const auto it = std::ranges::max_element(m_shapes,
		[](const auto& a, const auto& b) {
			return a->GetArea() < b->GetArea();
		}
	);

	return it->get();
}

IShape* Program::FindSmallestPerimeter()
{
    if (std::ranges::begin(m_shapes) == std::ranges::end(m_shapes))
	{
		throw std::runtime_error(Errors::NO_SHAPES);
	}

	const auto it = std::ranges::min_element(m_shapes,
		[](const auto& a, const auto& b) {
			return a->GetPerimeter() < b->GetPerimeter();
		}
	);

	return it->get();
}
