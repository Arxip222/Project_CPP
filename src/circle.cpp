//
// Created by Arhip on 22.03.2025.
//

#include "../circle.h"
#include "../segment.h"

namespace geometry {

Circle::Circle(Point center, int radius) : center(std::move(center)), radius(radius) {
}

IShape &Circle::Move(const Vector &vector) {
    center.Move(vector);
    return *this;
}

bool Circle::ContainsPoint(const Point &point) const {
    int dx = point.x - center.x;
    int dy = point.y - center.y;
    return dx * dx + dy * dy <= radius * radius;
}

bool Circle::CrossesSegment(const Segment &segment) const {
    Vector to_center(center.x - segment.start.x, center.y - segment.start.y);

    Vector segment_dir(segment.end.x - segment.start.x, segment.end.y - segment.start.y);

    int projection = (to_center.x * segment_dir.x + to_center.y * segment_dir.y) /
                     (segment_dir.x * segment_dir.x + segment_dir.y * segment_dir.y);

    projection = std::max(0, std::min(1, projection));

    Point closest_point(segment.start.x + projection * segment_dir.x, segment.start.y + projection * segment_dir.y);

    int dx = closest_point.x - center.x;
    int dy = closest_point.y - center.y;
    int distance_squared = dx * dx + dy * dy;

    return distance_squared <= radius * radius;
}

std::unique_ptr<IShape> Circle::Clone() const {
    return std::make_unique<Circle>(*this);
}

std::string Circle::ToString() const {
    return "Circle(" + center.ToString() + ", " + std::to_string(radius) + ")";
}

}  // namespace geometry
