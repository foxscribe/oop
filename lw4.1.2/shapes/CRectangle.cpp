#include "../include/CRectangle.hpp"
#include <format>


CRectangle::CRectangle(CPoint start, double width, double height, uint32_t outline, uint32_t fill)
    : m_start(start), m_width(width), m_height(height), m_outline(outline), m_fill(fill)
{
}

double CRectangle::GetArea() const
{
    return m_width * m_height;
}

double CRectangle::GetPerimeter() const
{
    return 2 * (m_width + m_height);
}

std::string CRectangle::ToString() const
{
    return std::format("rectangle(start={}, width={}, height={})", m_start, m_width, m_height);
}

uint32_t CRectangle::GetOutlineColor() const
{
    return m_outline;
}

uint32_t CRectangle::GetFillColor() const
{
    return m_fill;
}

CPoint CRectangle::GetLeftTop() const
{
    return m_start;
}

CPoint CRectangle::GetRightBottom() const
{
    return CPoint{
        .x = m_start.x + m_width,
        .y = m_start.y + m_height
    };
}

double CRectangle::GetWidth() const
{
    return m_width;
}

double CRectangle::GetHeight() const
{
    return m_height;
}
