//
// Created by Arhip on 22.03.2025.
//

#include "../ray.h"

#include "../segment.h"

namespace geometry {

Ray::Ray(Point origin, const Vector &direction) : origin(std::move(origin)), direction(direction) {
}

Ray::Ray(Point fi, const Point &se) : origin(std::move(fi)), direction(se - fi) {
}

IShape &Ray::Move(const Vector &vector) {
    origin.Move(vector);
    return *this;
}

bool Ray::ContainsPoint(const Point &point) const {
    Vector to_point(point.x - origin.x, point.y - origin.y);

    int cross = direction.x * to_point.y - direction.y * to_point.x;
    if (cross != 0) {
        return false;
    }

    int dot = direction.x * to_point.x + direction.y * to_point.y;
    return dot >= 0;
}

bool Ray::CrossesSegment(const Segment &segment) const {
    Vector ray_dir = direction;

    Vector seg_dir(segment.end.x - segment.start.x, segment.end.y - segment.start.y);

    Vector origin_to_start(segment.start.x - origin.x, segment.start.y - origin.y);

    double cross_ray_seg = ray_dir.x * seg_dir.y - ray_dir.y * seg_dir.x;
    double cr = ray_dir.x * origin_to_start.y - ray_dir.y * origin_to_start.x;
    double cross_seg_origin = seg_dir.x * origin_to_start.y - seg_dir.y * origin_to_start.x;

    if (std::abs(cross_ray_seg) < 1e-9) {
        return std::abs(cr) < 1e-9;
    }

    double t = cross_seg_origin / cross_ray_seg;
    double u = cr / cross_ray_seg;

    return t >= 0 && u >= 0 && u <= 1;
}

std::unique_ptr<IShape> Ray::Clone() const {
    return std::make_unique<Ray>(*this);
}

std::string Ray::ToString() const {
    return "Ray(Point(" + std::to_string(origin.x) + ", " + std::to_string(origin.y) + "), Vector(" +
           std::to_string(direction.x) + ", " + std::to_string(direction.y) + "))";
}

}  // namespace geometry
