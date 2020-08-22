//
// Created by claul on 6/7/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_COLOUR_H
#define RAYTRACINGINONEWEEKEND_COLOUR_H

#include "Vec3.h"
#include "Ray.h"
#include "../Assets/Collidables.h"
#include <iostream>
#include <optional>

void write_colour(std::ostream& out, colour pixel_colour) {
    out << static_cast<int>(255.999 * pixel_colour.x()) << ' '
        << static_cast<int>(255.999 * pixel_colour.y()) << ' '
        << static_cast<int>(255.999 * pixel_colour.z()) << '\n';
}

static colour rayColours(const Ray& r, const Collidables& world) {
    constexpr  double infinity = std::numeric_limits<double>::infinity();
    HitRecord hitRecord;
    bool hasHit = world.hit(r, 0, infinity, hitRecord);

    // adjust colour if it hit to demonstrate shading
    if (hasHit) {
        return 0.5 * (hitRecord.normal + colour(1, 1, 1));
    }

    Vec3 unitDirection = Vec3::unit_vector(r.getDirection());
    auto closestHitPoint = 0.5 * (unitDirection.y() + 1.0); // goes from 0 to 1 aka bottom to top
    // linear blend:                   start value                            end value
    return (1.0 - closestHitPoint) * colour(1.0, 1.0, 1.0) + closestHitPoint * colour(0.5, 0.7, 1.0);
};


#endif //RAYTRACINGINONEWEEKEND_COLOUR_H
