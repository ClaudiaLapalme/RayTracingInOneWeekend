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
    auto a = vec3::dot(this->getDirection(), this->getDirection()); // t^2b dot b
    auto b = 2.0 * vec3::dot(oc, this->getDirection()); // 2tb dot (A - C)
    auto c = vec3::dot(oc, oc) - radius * radius; // (A - C) dot (A - C) - r^2
    auto discriminant = b * b - 4 * a * c;

    if (discriminant < 0 ) { // didn't hit
        return {};
    }
    else { // determines if it hit 1 or 2 points on the sphere
        return (-b - sqrt(discriminant)) / (2.0 * a);
    }
}
