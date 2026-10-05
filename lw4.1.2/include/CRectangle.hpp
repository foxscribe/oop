#pragma once

#include "CPoint.hpp"
#include "ISolidShape.hpp"
#include <cstdint>

class CRectangle : public ISolidShape
{
public:
    CRectangle(CPoint start, double width, double height, uint32_t outline, uint32_t fill);

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    uint32_t GetOutlineColor() const override;
    uint32_t GetFillColor() const override;
    CPoint GetLeftTop() const;
    CPoint GetRightBottom() const;
    double GetWidth() const;
    double GetHeight() const;

private:
    uint32_t m_outline, m_fill;
    double m_width, m_height;
    CPoint m_start;
};
