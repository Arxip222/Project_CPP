//
// Created by Arhip on 22.03.2025.
//

#ifndef HSEPROJECT_VECTOR_H
#define HSEPROJECT_VECTOR_H

namespace geometry {

class Vector {
   public:
    int x, y;

    explicit Vector(int x = 0, int y = 0);
    Vector operator+(const Vector &other) const;
    Vector operator-(const Vector &other) const;
    Vector operator*(int scalar) const;
    Vector operator/(int scalar) const;
    Vector &operator+=(const Vector &other);
    Vector &operator-=(const Vector &other);
    Vector &operator*=(int scalar);
    Vector &operator/=(int scalar);
    bool operator==(const Vector &other) const;
};

}  // namespace geometry

#endif  // HSEPROJECT_VECTOR_H
