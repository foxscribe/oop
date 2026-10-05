#pragma once

#include "CPoint.hpp"
#include "ISolidShape.hpp"
#include <cstdint>

class CCircle : ISolidShape
{
public:
    CCircle(CPoint center, double radius, uint32_t outline, uint32_t fill);

    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    uint32_t GetOutlineColor() const;
    uint32_t GetFillColor() const;
    CPoint GetCenter() const;
    double GetRadius() const;

private:
    uint32_t m_outline, m_fill;
    CPoint m_center;
    double m_radius;
};
