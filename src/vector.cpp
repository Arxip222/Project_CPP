#include "../vector.h"

namespace geometry {

Vector::Vector(int x, int y) : x(x), y(y) {
}

Vector Vector::operator+(const Vector &other) const {
    return Vector{x + other.x, y + other.y};
}

Vector Vector::operator-(const Vector &other) const {
    return Vector{x - other.x, y - other.y};
}

Vector Vector::operator*(int scalar) const {
    return Vector{x * scalar, y * scalar};
}

Vector Vector::operator/(int scalar) const {
    return Vector{x / scalar, y / scalar};
}

Vector &Vector::operator+=(const Vector &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector &Vector::operator-=(const Vector &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector &Vector::operator*=(int scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector &Vector::operator/=(int scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector::operator==(const Vector &other) const {
    return x == other.x && y == other.y;
}

}  // namespace geometry
