#pragma once

#include "CPoint.hpp"
#include "IShape.hpp"
#include <cstdint>

class CLineSegment : public IShape
{
public:
    CLineSegment(CPoint start, CPoint end, uint32_t outline);

    double GetArea() const override;
    double GetPerimeter() const override;
    std::string ToString() const override;
    uint32_t GetOutlineColor() const override;
    CPoint GetStartPoint() const;
    CPoint GetEndPoint() const;

private:
    CPoint m_start, m_end;
    uint32_t m_outline;
};
