//
// Created by claul on 6/7/2020.
//

#include "../../Headers/Utilities/Ray.h"

Ray Ray::raySetup(double aspectRatio, double u, double v) {
    constexpr double viewportHeight = 2.0;
    constexpr double focalLength = 1.0;
    const auto viewportWidth = aspectRatio * viewportHeight;

    auto origin = point3(0, 0, 0);
    auto horizontal = point3(viewportWidth, 0, 0);
    auto vertical = point3(0, viewportHeight, 0);
    auto bottomLeftCorner = origin - (horizontal / 2 + vertical / 2 + Vec3(0, 0, focalLength));

    return Ray(origin, bottomLeftCorner + u * horizontal + v * vertical - origin);
}
