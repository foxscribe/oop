#pragma once

#include <ostream>

struct EquationRoots
{
    int numRoots;
    double roots[2];

    bool operator==(const EquationRoots& other) const;
    bool operator!=(const EquationRoots& other) const;
};

std::ostream& operator<<(std::ostream& os, const EquationRoots& roots);

// Вычисляем корни квадратного уравнения ax^2 + bx + c = 0
EquationRoots Solve(double a, double b, double c);
