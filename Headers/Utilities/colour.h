//
// Created by claul on 6/7/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_COLOUR_H
#define RAYTRACINGINONEWEEKEND_COLOUR_H

#include "Vec3.h"
#include "Ray.h"
#include "../Assets/Collidables.h"
#include <iostream>

void write_colour(std::ostream& out, Colour pixel_colour, int samplesPerPixel) {

    // divide colours by the number of pixels
    auto scale = 1.0 / samplesPerPixel; // more samples = less jagged
    auto r = sqrt(scale * pixel_colour.x());
    auto g = sqrt(scale * pixel_colour.y());
    auto b = sqrt(scale * pixel_colour.z());

    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}

static Colour rayColours(const Ray& r, const Collidables& world, const int depth) {

    // cut the recursion if it hit the limit of surfaces to bounce off of
    if (depth <= 0) {
        return {0, 0, 0};
    }

    constexpr  double infinity = std::numeric_limits<double>::infinity();
    HitRecord hitRecord{};
    bool hasHit = world.hit(r, 0.001, infinity, hitRecord); // 0.001 to prevent shadow acne

    // adjust colour if it hit to demonstrate shading
    if (hasHit) {
        Ray scattered;
        Colour attenuation;

        if (hitRecord.materialPtr->scatterLight(r, hitRecord, attenuation, scattered)) {
            return attenuation * rayColours(scattered, world, depth - 1);
        }

        return Colour{0, 0, 0};
    }

    Vec3 unitDirection = Vec3::unit_vector(r.getDirection());
    auto closestHitPoint = 0.5 * (unitDirection.y() + 1.0); // goes from 0 to 1 aka bottom to top
    // linear blend:                   start value                            end value
    return (1.0 - closestHitPoint) * Colour(1.0, 1.0, 1.0) + closestHitPoint * Colour(0.5, 0.7, 1.0);
}

#endif //RAYTRACINGINONEWEEKEND_COLOUR_H
