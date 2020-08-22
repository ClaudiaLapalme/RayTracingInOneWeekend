//
// Created by claul on 8/22/2020.
//

#include "../../Headers/Assets/Camera.h"

#include <random>

Camera::Camera(const double viewportHeight, const double viewportWidth,
               const double focalLength) {
    origin = point3(0.0, 0.0, 0.0);
    horizontal = Vec3(viewportWidth, 0.0, 0.0);
    vertical = Vec3(0.0, viewportHeight, 0.0);
    lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - Vec3(0.0, 0.0, focalLength);
}

Ray Camera::getRay(const double u, const double v) const {
    return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
