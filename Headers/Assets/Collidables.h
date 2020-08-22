//
// Created by claul on 8/21/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_COLLIDABLES_H
#define RAYTRACINGINONEWEEKEND_COLLIDABLES_H

#include "../Utilities/Ray.h"
#include "../Utilities/HitRecord.h"

class Collidables {
public:
    Collidables() = default;

    virtual bool hit(const Ray& ray, const double tMin, const double tMax, HitRecord& hitRecord) const = 0;
};


#endif //RAYTRACINGINONEWEEKEND_COLLIDABLES_H
