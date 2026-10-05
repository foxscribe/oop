#pragma once

#include "CPoint.hpp"
#include "ISolidShape.hpp"
#include <cstdint>

class CTriangle : public ISolidShape
{
public:
    CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outline, uint32_t fill);

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    uint32_t GetOutlineColor() const override;
    uint32_t GetFillColor() const override;
    CPoint GetVertex1() const;
    CPoint GetVertex2() const;
    CPoint GetVertex3() const;

private:
    CPoint m_vertex1, m_vertex2, m_vertex3;
    uint32_t m_outline, m_fill;
};
