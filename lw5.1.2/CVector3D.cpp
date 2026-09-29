#include "CVector3D.hpp"
#include <cmath>

CVector3D::CVector3D() : x(0.0), y(0.0), z(0.0)
{}

CVector3D::CVector3D(double x0, double y0, double z0) : x(x0), y(y0), z(z0)
{}

double CVector3D::GetLength() const
{
    return std::sqrt(x * x + y * y + z * z);
}

void CVector3D::Normalize()
{
    double length = GetLength();
    if (length > 0.0)
    {
        x /= length;
        y /= length;
        z /= length;
    }
}

CVector3D CVector3D::operator+() const
{
    return CVector3D(x, y, z);
}

CVector3D CVector3D::operator-() const
{
    return CVector3D(-x, -y, -z);
}

CVector3D CVector3D::operator+(const CVector3D& other) const
{
    return CVector3D(x + other.x, y + other.y, z + other.z);
}

CVector3D CVector3D::operator-(const CVector3D& other) const
{
    return CVector3D(x - other.x, y - other.y, z - other.z);
}

CVector3D& CVector3D::operator+=(const CVector3D& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

CVector3D& CVector3D::operator-=(const CVector3D& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

CVector3D CVector3D::operator*(double scalar) const
{
    return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D CVector3D::operator/(double scalar) const
{
    if (scalar != 0.0)
    {
        return CVector3D(x / scalar, y / scalar, z / scalar);
    }
    return CVector3D(0.0, 0.0, 0.0);
}

CVector3D& CVector3D::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

CVector3D& CVector3D::operator/=(double scalar)
{
    if (scalar != 0.0)
    {
        x /= scalar;
        y /= scalar;
        z /= scalar;
    }
    return *this;
}

bool CVector3D::operator==(const CVector3D& other) const
{
    return (x == other.x && y == other.y && z == other.z);
}

bool CVector3D::operator!=(const CVector3D& other) const
{
    return !(*this == other);
}

CVector3D operator*(double scalar, const CVector3D& vector)
{
    return vector * scalar;
}

std::ostream& operator<<(std::ostream& os, const CVector3D& vector)
{
    os << vector.x << ", " << vector.y << ", " << vector.z;
    return os;
}

std::istream& operator>>(std::istream& is, CVector3D& vector)
{
    char comma1, comma2;
    is >> vector.x >> comma1 >> vector.y >> comma2 >> vector.z;

    return is;
}

// Вычисляет результат скалярного произведения двух трехмерных векторов
double DotProduct(const CVector3D& v1, const CVector3D& v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

// Вычисляет результат векторного произведения двух трехмерных векторов
CVector3D CrossProduct(const CVector3D& v1, const CVector3D& v2)
{
    return CVector3D(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x
    );
}

CVector3D Normalize(const CVector3D& v)
{
    CVector3D result = v;
    result.Normalize();
    return result;
}
