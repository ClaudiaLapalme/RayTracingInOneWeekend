//
// Created by claul on 6/7/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_COLOUR_H
#define RAYTRACINGINONEWEEKEND_COLOUR_H

#include "vec3.h"
#include "ray.h"
#include <iostream>
#include <optional>

void write_colour(std::ostream& out, colour pixel_colour) {
    out << static_cast<int>(255.999 * pixel_colour.x()) << ' '
        << static_cast<int>(255.999 * pixel_colour.y()) << ' '
        << static_cast<int>(255.999 * pixel_colour.z()) << '\n';
}

static colour rayColours(const ray& r) {
    std::optional<double> closestHitPoint = r.hitSphere(point3(0, 0, -1), 0.5);

    // adjust colour if it hit to demonstrate shading
    if (closestHitPoint) {
        vec3 normal = vec3::unit_vector(r.at(*closestHitPoint) - vec3(0, 0, -1));
        return 0.5 * colour(normal.x() + 1, normal.y() + 1, normal.z() + 1);
    }

    vec3 unitDirection = vec3::unit_vector(r.getDirection());
    closestHitPoint = 0.5 * (unitDirection.y() + 1.0); // goes from 0 to 1 aka bottom to top
    // linear blend:                   start value                            end value
    return (1.0 - *closestHitPoint) * colour(1.0, 1.0, 1.0) + *closestHitPoint * colour(0.5, 0.7, 1.0);
};


#endif //RAYTRACINGINONEWEEKEND_COLOUR_H
