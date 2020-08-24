//
// Created by claul on 6/7/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_RAY_H
#define RAYTRACINGINONEWEEKEND_RAY_H

#include <optional>
#include "Vec3.h"

class Ray {
private:
    Point3 origin;
    Vec3 direction;
public:
    Ray() = default;
    Ray(const Point3& origin, const Vec3& direction) : origin(origin), direction(direction) {};

    Point3 getOrigin() const { return this->origin; };
    Vec3 getDirection() const { return this->direction; };

    Point3 at(double t) const { return origin + t * direction; };
};

#endif //RAYTRACINGINONEWEEKEND_RAY_H
