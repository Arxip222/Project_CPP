//
// Created by Arhip on 22.03.2025.
//

#ifndef HSEPROJECT_LINE_H
#define HSEPROJECT_LINE_H

#include "IShape.h"

namespace geometry {

class Line : public IShape {
   public:
    int A, B, C;

    Line(int a, int b, int c);
    Line(const Point &p1, const Point &p2);
    IShape &Move(const Vector &vector) override;
    bool ContainsPoint(const Point &point) const override;
    bool CrossesSegment(const Segment &segment) const override;
    std::unique_ptr<IShape> Clone() const override;
    std::string ToString() const override;
};

}  // namespace geometry

#endif  // HSEPROJECT_LINE_H
