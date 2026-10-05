#pragma once

#include <format>

class CPoint
{
public:
    bool operator==(const CPoint& other) const;
    bool operator!=(const CPoint& other) const;

    double Distance(const CPoint& other) const;

    double x, y;
};

template <>
struct std::formatter<CPoint> : std::formatter<double>
{
    auto format(const CPoint& p, std::format_context& ctx) const
    {
        auto out = ctx.out();
        out = std::format_to(out, "(");
        out = std::formatter<double>::format(p.x, ctx);
        out = std::format_to(out, ", ");
        out = std::formatter<double>::format(p.y, ctx);
        return std::format_to(out, ")");
    }
};
