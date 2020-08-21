//
// Created by claul on 6/7/2020.
//

#include "../Headers/Utilities/ray.h"

ray ray::raySetup(double aspectRatio, double u, double v) {
    constexpr double viewportHeight = 2.0;
    constexpr double focalLength = 1.0;
    const auto viewportWidth = aspectRatio * viewportHeight;

    auto origin = point3(0, 0, 0);
    auto horizontal = point3(viewportWidth, 0, 0);
    auto vertical = point3(0, viewportHeight, 0);
    auto bottomLeftCorner = origin - (horizontal / 2 + vertical / 2 + vec3(0, 0, focalLength));

    return ray(origin, bottomLeftCorner + u * horizontal + v * vertical - origin);
}

std::optional<double> ray::hitSphere(const point3 &center, double radius) const {
    vec3 oc = this->getOrigin() - center;
    auto a = this->getDirection().length_squared(); // dot product of a vector w/ itself = length square of the vector
    auto halfB = vec3::dot(oc, this->getDirection());
    auto c = oc.length_squared() - radius * radius; // dot product of a vector w/ itself = length square of the vector
    auto discriminant = halfB * halfB - a * c;

    if (discriminant < 0 ) { // didn't hit
        return {};
    }
    else { // determines if it hit 1 or 2 points on the sphere
        return (-halfB - sqrt(discriminant)) / a;
    }
}
