//
// Created by Arhip on 22.03.2025.
//

#include "../polygon.h"

#include "../segment.h"

namespace geometry {

Polygon::Polygon(const std::vector<Point> &vertices) : vertices(vertices) {
}

IShape &Polygon::Move(const Vector &vector) {
    for (auto &vertex : vertices) {
        vertex.Move(vector);
    }
    return *this;
}

bool Polygon::ContainsPoint(const Point &point) const {
    int crossings = 0;
    size_t n = vertices.size();

    for (size_t i = 0; i < n; ++i) {
        const Point &p1 = vertices[i];
        const Point &p2 = vertices[(i + 1) % n];

        Segment edge(p1, p2);
        if (edge.ContainsPoint(point)) {
            return true;
        }

        if ((p1.y > point.y) != (p2.y > point.y)) {
            int x_intersect = (p2.x - p1.x) * (point.y - p1.y) / (p2.y - p1.y) + p1.x;
            if (point.x <= x_intersect) {
                crossings++;
            }
        }
    }

    return crossings % 2 == 1;
}

bool Polygon::CrossesSegment(const Segment &segment) const {
    size_t n = vertices.size();

    for (size_t i = 0; i < n; ++i) {
        const Point &p1 = vertices[i];
        const Point &p2 = vertices[(i + 1) % n];

        Segment edge(p1, p2);
        if (edge.CrossesSegment(segment)) {
            return true;
        }
    }

    return false;
}

std::unique_ptr<IShape> Polygon::Clone() const {
    return std::make_unique<Polygon>(*this);
}

std::string Polygon::ToString() const {
    std::string result = "Polygon(";
    for (size_t i = 0; i < vertices.size(); ++i) {
        result += vertices[i].ToString();
        if (i < vertices.size() - 1) {
            result += ", ";
        }
    }
    result += ")";
    return result;
}

}  // namespace geometry
