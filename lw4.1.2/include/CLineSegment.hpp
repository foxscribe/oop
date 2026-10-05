#pragma once

#include "CPoint.hpp"
#include "IShape.hpp"
#include <cstdint>

class CLineSegment : IShape
{
public:
    CLineSegment(CPoint start, CPoint end, uint32_t outline);

    double GetArea() const;
    double GetPerimeter() const;
    std::string ToString() const;
    uint32_t GetOutlineColor() const;
    CPoint GetStartPoint() const;
    CPoint GetEndPoint() const;

private:
    CPoint m_start, m_end;
    uint32_t m_outline;
};
