//
// Created by claul on 6/7/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_COLOUR_H
#define RAYTRACINGINONEWEEKEND_COLOUR_H

#include "Utilities/vec3.h"
#include "Utilities/ray.h"
#include <iostream>

void write_colour(std::ostream& out, colour pixel_colour) {
    out << static_cast<int>(255.999 * pixel_colour.x()) << ' '
        << static_cast<int>(255.999 * pixel_colour.y()) << ' '
        << static_cast<int>(255.999 * pixel_colour.z()) << '\n';
}

static colour rayColours(const ray& r) {
    if (r.hitSphere(point3(0, 0, -1), 0.5)) {
        return colour(1.0, 0, 0);
    }
    vec3 unitDirection = vec3::unit_vector(r.getDirection());
    auto t = 0.5 * (unitDirection.y() + 1.0); // goes from 0 to 1 aka bottom to top
    // linear blend:                   start value                            end value
    return (1.0 - t) * colour(1.0, 1.0, 1.0) + t * colour(0.5, 0.7, 1.0);
};


#endif //RAYTRACINGINONEWEEKEND_COLOUR_H
