
//
// Created by Arhip on 22.03.2025.
//

#include "../point.h"

#include "../segment.h"

namespace geometry {

Point::Point(int x, int y) : x(x), y(y) {
}

IShape &Point::Move(const Vector &vector) {
    x += vector.x;
    y += vector.y;
    return *this;
}

bool Point::ContainsPoint(const Point &point) const {
    return x == point.x && y == point.y;
}

bool Point::CrossesSegment(const Segment &segment) const {
    const Point &start = segment.start;
    const Point &end = segment.end;

    int cross = (end.x - start.x) * (y - start.y) - (end.y - start.y) * (x - start.x);
    if (cross != 0) {
        return false;
    }

    int min_x = std::min(start.x, end.x);
    int max_x = std::max(start.x, end.x);
    int min_y = std::min(start.y, end.y);
    int max_y = std::max(start.y, end.y);

    return x >= min_x && x <= max_x && y >= min_y && y <= max_y;
}

std::unique_ptr<IShape> Point::Clone() const {
    return std::make_unique<Point>(*this);
}

Vector Point::operator-(const Point &other) const {
    return Vector{x - other.x, y - other.y};
}

std::string Point::ToString() const {
    return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

}  // namespace geometry
