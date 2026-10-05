#pragma once

#include "CPoint.hpp"
#include "ISolidShape.hpp"
#include <cstdint>

class CRectangle : ISolidShape
{
public:
    CRectangle(CPoint start, double width, double height, uint32_t outline, uint32_t fill);

    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    uint32_t GetOutlineColor() const;
    uint32_t GetFillColor() const;
    CPoint GetLeftTop() const;
    CPoint GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;

private:
    uint32_t m_outline, m_fill;
    double m_width, m_height;
    CPoint m_start;
};
