//
// Created by Arhip on 22.03.2025.
//

#ifndef HSEPROJECT_RAY_H
#define HSEPROJECT_RAY_H

#include "IShape.h"
#include "point.h"

namespace geometry {

class Ray : public IShape {
   public:
    Ray(Point origin, const Point &direction);

    Point origin;
    Vector direction;

    Ray(Point origin, const Vector &direction);
    IShape &Move(const Vector &vector) override;
    bool ContainsPoint(const Point &point) const override;
    bool CrossesSegment(const Segment &segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
};

}  // namespace geometry

#endif  // HSEPROJECT_RAY_H
