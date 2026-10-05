#include "../include/CLineSegment.hpp"
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <format>

namespace
{
    inline constexpr auto OUTPUT_FORMAT =
        "line(start={}, end={}, outline=#{:X}, S={}, P={})";
}

CLineSegment::CLineSegment(CPoint start, CPoint end, uint32_t outline)
    : m_start(start), m_end(end), m_outline(outline)
{
}

double CLineSegment::GetArea() const
{
    return 0;
}

double CLineSegment::GetPerimeter() const
{
    return m_start.Distance(m_end);
}

std::string CLineSegment::ToString() const
{
    return std::format(OUTPUT_FORMAT, m_start, m_end, m_outline, GetArea(), GetPerimeter());
}

uint32_t CLineSegment::GetOutlineColor() const
{
    return m_outline;
}

CPoint CLineSegment::GetStartPoint() const
{
    return m_start;
}

CPoint CLineSegment::GetEndPoint() const
{
    return m_end;
}
