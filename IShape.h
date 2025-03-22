//
// Created by Arhip on 22.03.2025.
//

#ifndef HSEPROJECT_ISHAPE_H
#define HSEPROJECT_ISHAPE_H

#include <memory>

#include "vector.h"

namespace geometry {

class Point;
class Segment;

class IShape {
   public:
    virtual ~IShape() = default;
    virtual IShape &Move(const Vector &vector) = 0;
    virtual bool ContainsPoint(const Point &point) const = 0;
    virtual bool CrossesSegment(const Segment &segment) const = 0;
    virtual std::unique_ptr<IShape> Clone() const = 0;
    virtual std::string ToString() const = 0;
};

}  // namespace geometry

#endif  // HSEPROJECT_ISHAPE_H
