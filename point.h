//
// Created by Arhip on 22.03.2025.
//

#ifndef HSEPROJECT_POINT_H
#define HSEPROJECT_POINT_H

#include "IShape.h"

namespace geometry {

class Point : public IShape, public geometry::Vector {
   public:
    int x, y;

    explicit Point(int x = 0, int y = 0);
    IShape &Move(const Vector &vector) override;
    bool ContainsPoint(const Point &point) const override;
    bool CrossesSegment(const Segment &segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
    Vector operator-(const Point &other) const;
};

}  // namespace geometry

#endif  // HSEPROJECT_POINT_H
