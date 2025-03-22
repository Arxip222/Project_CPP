//
// Created by Arhip on 22.03.2025.
//

#ifndef HSEPROJECT_CIRCLE_H
#define HSEPROJECT_CIRCLE_H

#include "point.h"

namespace geometry {

class Circle : public IShape {
   public:
    Point center;
    int radius;

    Circle(Point center, int radius);
    IShape &Move(const Vector &vector) override;
    bool ContainsPoint(const Point &point) const override;
    bool CrossesSegment(const Segment &segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
};

}  // namespace geometry

#endif  // HSEPROJECT_CIRCLE_H
