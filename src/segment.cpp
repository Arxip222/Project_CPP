//
// Created by Arhip on 22.03.2025.
//

#include "../segment.h"

namespace geometry {

Segment::Segment(Point start, Point end) : start(std::move(start)), end(std::move(end)) {
}

IShape &Segment::Move(const Vector &vector) {
    start.Move(vector);
    end.Move(vector);
    return *this;
}

bool Segment::ContainsPoint(const Point &point) const {
    int cross = (end.x - start.x) * (point.y - start.y) - (end.y - start.y) * (point.x - start.x);
    if (cross != 0) {
        return false;
    }

    int min_x = std::min(start.x, end.x);
    int max_x = std::max(start.x, end.x);
    int min_y = std::min(start.y, end.y);
    int max_y = std::max(start.y, end.y);

    return point.x >= min_x && point.x <= max_x && point.y >= min_y && point.y <= max_y;
}

bool Segment::CrossesSegment(const Segment &other) const {
    auto orientation = [](const Point &p1, const Point &p2, const Point &p3) -> int {
        int val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
        if (val == 0) {
            return 0;
        }
        return (val > 0) ? 1 : 2;
    };

    auto on_segment = [](const Point &p, const Point &q, const Point &r) -> bool {
        return q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) && q.y <= std::max(p.y, r.y) &&
               q.y >= std::min(p.y, r.y);
    };

    int o1 = orientation(start, end, other.start);
    int o2 = orientation(start, end, other.end);
    int o3 = orientation(other.start, other.end, start);
    int o4 = orientation(other.start, other.end, end);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && on_segment(start, other.start, end)) {
        return true;
    }
    if (o2 == 0 && on_segment(start, other.end, end)) {
        return true;
    }
    if (o3 == 0 && on_segment(other.start, start, other.end)) {
        return true;
    }
    if (o4 == 0 && on_segment(other.start, end, other.end)) {
        return true;
    }

    return false;
}

std::unique_ptr<IShape> Segment::Clone() const {
    return std::make_unique<Segment>(*this);
}

std::string Segment::ToString() const {
    return "Segment(" + start.ToString() + ", " + end.ToString() + ")";
}

}  // namespace geometry