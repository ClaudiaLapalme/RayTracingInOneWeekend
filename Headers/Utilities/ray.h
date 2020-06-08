//
// Created by claul on 6/7/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_RAY_H
#define RAYTRACINGINONEWEEKEND_RAY_H

#include "vec3.h"

class ray {
private:
    point3 origin;
    vec3 direction;
public:
    ray() = default;
    ray(const point3& origin, const vec3& direction) : origin(origin), direction(direction) {};
    static ray raySetup(double aspectRatio, double u, double v);
    bool hitSphere(const point3& center, double radius) const;

    point3 getOrigin() const { return this->origin; };
    vec3 getDirection() const { return this->direction; };

    point3 at(double t) const { return origin + t * direction; };
};


#endif //RAYTRACINGINONEWEEKEND_RAY_H
