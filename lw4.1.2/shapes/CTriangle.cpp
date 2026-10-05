#include "../include/CTriangle.hpp"
#include <cstdlib>
#include <format>

namespace
{
    inline constexpr auto OUTPUT_FORMAT =
        "triangle(v1={}, v2={}, v3={}, outline=#{:X}, fill=#{:X}, S={}, P={})";
}

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outline, uint32_t fill)
    : m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3), m_outline(outline), m_fill(fill)
{
}

double CTriangle::GetArea() const
{
    // (1 / 2) |[x1 (y2 – y3 ) + x2 (y3 – y1 ) + x3(y1 – y2)]|
    double a = m_vertex1.x * (m_vertex2.y - m_vertex3.y);
    double b = m_vertex2.x * (m_vertex3.y - m_vertex1.y);
    double c = m_vertex3.x * (m_vertex1.y - m_vertex2.y);
    return std::abs(a + b + c) / 2;
}

double CTriangle::GetPerimeter() const
{
    return m_vertex1.Distance(m_vertex2)
        + m_vertex2.Distance(m_vertex3)
        + m_vertex3.Distance(m_vertex1);
}

std::string CTriangle::ToString() const
{
    return std::format(OUTPUT_FORMAT, m_vertex1, m_vertex2, m_vertex3,
        m_outline, m_fill, GetArea(), GetPerimeter());
}

uint32_t CTriangle::GetOutlineColor() const
{
    return m_outline;
}

uint32_t CTriangle::GetFillColor() const
{
    return m_fill;
}

CPoint CTriangle::GetVertex1() const
{
    return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
    return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
    return m_vertex3;
}
