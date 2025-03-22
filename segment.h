//
// Created by Arhip on 22.03.2025.
//

#ifndef HSEPROJECT_SEGMENT_H
#define HSEPROJECT_SEGMENT_H

#include "IShape.h"
#include "point.h"

namespace geometry {

class Segment : public IShape {
   public:
    Point start, end;

    Segment(Point start, Point end);

    IShape &Move(const Vector &vector) override;

    bool ContainsPoint(const Point &point) const override;

    bool CrossesSegment(const Segment &segment) const override;

    std::unique_ptr<IShape> Clone() const override;

    std::string ToString() const override;
};

}  // namespace geometry

#endif  // HSEPROJECT_SEGMENT_H
