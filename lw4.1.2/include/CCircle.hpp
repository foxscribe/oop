#pragma once

#include "CPoint.hpp"
#include "ISolidShape.hpp"
#include <cstdint>

class CCircle : public ISolidShape
{
public:
    CCircle(CPoint center, double radius, uint32_t outline, uint32_t fill);

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    uint32_t GetOutlineColor() const override;
    uint32_t GetFillColor() const override;
    CPoint GetCenter() const;
    double GetRadius() const;

private:
    uint32_t m_outline, m_fill;
    CPoint m_center;
    double m_radius;
};
