#pragma once

#include "IShape.hpp"

#include <iostream>
#include <memory>
#include <vector>

class CShapeParser
{
    using VectorOfShapes = std::vector<std::unique_ptr<IShape>>;

public:
	explicit CShapeParser() = default;

	static void Parse(std::istream& input, VectorOfShapes& shapes);

private:
	static bool CheckStream(const std::istream& input);
	static void ParseCircle(std::istream& input, std::vector<std::unique_ptr<IShape>>& shapes);
	static void ParseLine(std::istream& input, std::vector<std::unique_ptr<IShape>>& shapes);
	static void ParseRectangle(std::istream& input, std::vector<std::unique_ptr<IShape>>& shapes);
	static void ParseTriangle(std::istream& input, std::vector<std::unique_ptr<IShape>>& shapes);
};
