#include "../include/CLineSegment.hpp"
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <format>

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
    return std::format("line(start={}, end={})", m_start, m_end);
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
