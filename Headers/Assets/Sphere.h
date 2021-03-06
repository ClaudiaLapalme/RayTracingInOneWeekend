//
// Created by claul on 8/21/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_SPHERE_H
#define RAYTRACINGINONEWEEKEND_SPHERE_H

#include "../Utilities/Vec3.h"
#include "Collidables.h"

class Sphere : public Collidables {
public:
    Sphere() = default;
    Sphere(const Point3 center, const double radius, std::shared_ptr<Material> materialPtr)
    : center(center), radius(radius), materialPtr(materialPtr) {};
    virtual bool hit(const Ray& ray, const double tMin, const double tMax, HitRecord& hitRecord) const override;

private:
    Point3 center;
    double radius;
    std::shared_ptr<Material> materialPtr;
};


#endif //RAYTRACINGINONEWEEKEND_SPHERE_H
