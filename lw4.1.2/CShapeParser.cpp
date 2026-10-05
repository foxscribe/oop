#include "include/CShapeParser.hpp"

#include "include/CCircle.hpp"
#include "include/CLineSegment.hpp"
#include "include/CRectangle.hpp"
#include "include/CTriangle.hpp"

#include <cstdint>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

namespace ShapeNames
{
	inline constexpr auto CIRCLE = "circle";
	inline constexpr auto LINE = "line";
	inline constexpr auto RECTANGLE = "rectangle";
	inline constexpr auto TRIANGLE = "triangle";
}

namespace Errors
{
    inline constexpr auto UNKNOWN_SHAPE = "unknown shape type";
    inline constexpr auto INVALID_PARAMETERS = "invalid parameters";
}

namespace
{
    inline constexpr auto DEFAULT_COLOR = 0x00FF00FF;
}

void CShapeParser::Parse(std::istream& input, VectorOfShapes& shapes)
{
    using ParseFunc = void(*)(std::istream&, VectorOfShapes& shapes);
    static const std::unordered_map<std::string, ParseFunc> parsers = {
        {ShapeNames::CIRCLE,    ParseCircle},
        {ShapeNames::LINE,      ParseLine},
        {ShapeNames::RECTANGLE, ParseRectangle},
        {ShapeNames::TRIANGLE,  ParseTriangle}
    };

	std::string line;

	while (std::getline(input, line))
	{
		if (line.empty())
		{
			continue;
		}

		std::stringstream stream(line);
		std::string shapeType;
		stream >> shapeType;

		auto it = parsers.find(shapeType);
        if (it != parsers.end())
        {
            it->second(stream, shapes);
        }
        else
        {
            throw std::invalid_argument(Errors::UNKNOWN_SHAPE);
        }
	}
}

bool CShapeParser::CheckStream(const std::istream& input)
{
	if (input.fail())
	{
		throw std::invalid_argument(Errors::INVALID_PARAMETERS);
		return false;
	}

	return true;
}

void CShapeParser::ParseCircle(std::istream& input, VectorOfShapes& shapes)
{
	CPoint center;
	double radius;
	uint32_t outlineColor = DEFAULT_COLOR;
	uint32_t fillColor = DEFAULT_COLOR;

	if (!(input >> center.x >> center.y >> radius))
	{
		CheckStream(input);
		return;
	}

	uint32_t colorValue;
	if (input >> std::hex >> colorValue)
	{
		outlineColor = colorValue;
	}

	if (input >> std::hex >> colorValue)
	{
		fillColor = colorValue;
	}

	auto circle = std::make_unique<CCircle>(center, radius, outlineColor, fillColor);
	shapes.push_back(std::move(circle));
}

void CShapeParser::ParseLine(std::istream& input, VectorOfShapes& shapes)
{
	CPoint startPoint;
	CPoint endPoint;
	uint32_t outlineColor = DEFAULT_COLOR;

	if (!(input >> startPoint.x >> startPoint.y >> endPoint.x >> endPoint.y))
	{
		CheckStream(input);
		return;
	}

	if (uint32_t colorValue; input >> std::hex >> colorValue)
	{
		outlineColor = colorValue;
	}

	auto line = std::make_unique<CLineSegment>(startPoint, endPoint, outlineColor);
	shapes.push_back(std::move(line));
}

void CShapeParser::ParseRectangle(std::istream& input, VectorOfShapes& shapes)
{
	CPoint startPoint;
	double width, height;
	uint32_t outlineColor = DEFAULT_COLOR;
	uint32_t fillColor = DEFAULT_COLOR;

	if (!(input >> startPoint.x >> startPoint.y >> width >> height))
	{
		CheckStream(input);
		return;
	}

	uint32_t colorValue;
	if (input >> std::hex >> colorValue)
	{
		outlineColor = colorValue;
	}

	if (input >> std::hex >> colorValue)
	{
		fillColor = colorValue;
	}

	auto rectangle = std::make_unique<CRectangle>(startPoint, width, height, outlineColor, fillColor);
	shapes.push_back(std::move(rectangle));
}

void CShapeParser::ParseTriangle(std::istream& input, VectorOfShapes& shapes)
{
	CPoint point1;
	CPoint point2;
	CPoint point3;
	uint32_t outlineColor = DEFAULT_COLOR;
	uint32_t fillColor = DEFAULT_COLOR;

	if (!(input >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y))
	{
		CheckStream(input);
		return;
	}

	uint32_t colorValue;
	if (input >> std::hex >> colorValue)
	{
		outlineColor = colorValue;
	}

	if (input >> std::hex >> colorValue)
	{
		fillColor = colorValue;
	}

	auto triangle = std::make_unique<CTriangle>(point1, point2, point3, outlineColor, fillColor);
	shapes.push_back(std::move(triangle));
}
