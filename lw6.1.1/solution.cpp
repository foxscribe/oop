#include "solution.hpp"
#include <cmath>
#include <stdexcept>
#include <string_view>

namespace
{
    // error messages
    inline const std::string ERR_INVALID_A = "Coefficient `a` cannot be zero";
    inline const std::string ERR_NO_ROOTS  = "No real roots found (D = 0)";

    // constants
    inline constexpr std::string_view NO_ROOTS = "(none)";
    inline constexpr char OPENING_PARENTHESIS  = '(';
    inline constexpr char CLOSING_PARENTHESIS  = ')';
}

EquationRoots Solve(double a, double b, double c)
{
    if (a == 0)
    {
        throw std::invalid_argument(ERR_INVALID_A);
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)
    {
        throw std::domain_error(ERR_NO_ROOTS);
    }

    EquationRoots result;
    if (discriminant == 0)
    {
        result.numRoots = 1;
        result.roots[0] = -b / (2.0 * a);
    }
    else
    {
        result.numRoots = 2;
        double sqrt_d = std::sqrt(discriminant);
        result.roots[0] = (-b - sqrt_d) / (2.0 * a);
        result.roots[1] = (-b + sqrt_d) / (2.0 * a);
    }

    return result;
}

bool EquationRoots::operator==(const EquationRoots& o) const
{
    if (numRoots != o.numRoots)
    {
        return false;
    }
    switch (numRoots)
    {
    case 0:
        return true;
    case 1:
        return roots[0] == o.roots[0];
    case 2:
        return roots[0] == o.roots[0] && roots[1] == o.roots[1];
    default:
        return false;
    }
}

bool EquationRoots::operator!=(const EquationRoots& o) const
{
    if (numRoots != o.numRoots)
    {
        return true;
    }
    switch (numRoots)
    {
    case 0:
        return false;
    case 1:
        return roots[0] != o.roots[0];
    case 2:
        return roots[0] != o.roots[0] || roots[1] != o.roots[1];
    default:
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const EquationRoots& roots)
{
    switch (roots.numRoots)
    {
    case 1:
        os << OPENING_PARENTHESIS << roots.roots[0] << CLOSING_PARENTHESIS;
        break;
    case 2:
        os << OPENING_PARENTHESIS << roots.roots[0] << ", " << roots.roots[1] << CLOSING_PARENTHESIS;
        break;
    default:
        os << NO_ROOTS;
        break;
    }
    return os;
}
