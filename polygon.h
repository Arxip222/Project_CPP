//
// Created by Arhip on 22.03.2025.
//

#ifndef HSEPROJECT_POLYGON_H
#define HSEPROJECT_POLYGON_H

#include <vector>

#include "point.h"

namespace geometry {

class Polygon : public IShape {
   public:
    std::vector<Point> vertices;

    explicit Polygon(const std::vector<Point> &vertices);
    IShape &Move(const Vector &vector) override;
    bool ContainsPoint(const Point &point) const override;
    bool CrossesSegment(const Segment &segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
};

}  // namespace geometry

#endif  // HSEPROJECT_POLYGON_H
