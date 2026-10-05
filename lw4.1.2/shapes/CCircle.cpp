#include "../include/CCircle.hpp"
#include <cstdint>
#include <format>
#include <numbers>

namespace
{
    inline constexpr auto OUTPUT_FORMAT =
        "circle(center={}, radius={}, outline=#{:X}, fill=#{:X}, S={}, P={})";
}

CCircle::CCircle(CPoint center, double radius, uint32_t outline, uint32_t fill)
    : m_center(center), m_radius(radius), m_outline(outline), m_fill(fill)
{
}

double CCircle::GetArea() const
{
    return std::numbers::pi * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
    return 2 * std::numbers::pi * m_radius;
}

std::string CCircle::ToString() const
{
    return std::format(OUTPUT_FORMAT, m_center, m_radius,
        m_outline, m_fill, GetArea(), GetPerimeter());
}

uint32_t CCircle::GetOutlineColor() const
{
    return m_outline;
}

uint32_t CCircle::GetFillColor() const
{
    return m_fill;
}

CPoint CCircle::GetCenter() const
{
    return m_center;
}

double CCircle::GetRadius() const
{
    return m_radius;
}
