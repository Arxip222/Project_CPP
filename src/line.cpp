//
// Created by Arhip on 22.03.2025.
//

#include "../line.h"
#include "../point.h"
#include "../segment.h"

namespace geometry {

Line::Line(int a, int b, int c) : A(a), B(b), C(c) {
}

Line::Line(const Point &p1, const Point &p2) {
    A = p2.y - p1.y;
    B = p1.x - p2.x;
    C = p2.x * p1.y - p1.x * p2.y;
}

IShape &Line::Move(const Vector &vector) {
    C -= A * vector.x + B * vector.y;
    return *this;
}

bool Line::ContainsPoint(const Point &point) const {
    return A * point.x + B * point.y + C == 0;
}

bool Line::CrossesSegment(const Segment &segment) const {
    int value_start = A * segment.start.x + B * segment.start.y + C;
    int value_end = A * segment.end.x + B * segment.end.y + C;

    if ((value_start > 0 && value_end < 0) || (value_start < 0 && value_end > 0)) {
        return true;
    }

    if (value_start == 0 || value_end == 0) {
        return true;
    }

    return false;
}

std::unique_ptr<IShape> Line::Clone() const {
    return std::make_unique<Line>(*this);
}

std::string Line::ToString() const {
    return "Line(" + std::to_string(A) + ", " + std::to_string(B) + ", " + std::to_string(C) + ")";
}

}  // namespace geometry