//
// Created by claul on 8/21/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_HITRECORD_H
#define RAYTRACINGINONEWEEKEND_HITRECORD_H

#include "Vec3.h"
#include "Ray.h"

struct HitRecord {
    Point3 point;
    Vec3 normal; // closest normal
    double t;
    bool frontFace;

    void setFaceNormal(const Ray& ray, const Vec3& outwardNormal) {
        frontFace = Vec3::dot(ray.getDirection(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

#endif //RAYTRACINGINONEWEEKEND_HITRECORD_H
