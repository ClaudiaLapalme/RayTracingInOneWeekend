//
// Created by claul on 8/22/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_CAMERA_H
#define RAYTRACINGINONEWEEKEND_CAMERA_H

#include "../Utilities/Vec3.h"
#include "../Utilities/Ray.h"

class Camera {
public:
    Camera() = default;
    Camera(const double viewportHeight, const double viewportWidth, const double focalLength);
    Ray getRay(const double u, const double v) const;

private:
    Point3 origin{};
    Point3 lowerLeftCorner{};
    Vec3 horizontal{};
    Vec3 vertical{};
};


#endif //RAYTRACINGINONEWEEKEND_CAMERA_H
