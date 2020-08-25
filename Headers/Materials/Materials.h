//
// Created by claul on 8/25/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_MATERIALS_H
#define RAYTRACINGINONEWEEKEND_MATERIALS_H

#include "../Utilities/Vec3.h"
#include "../Utilities/Ray.h"
#include "../Utilities/HitRecord.h"

struct HitRecord;

class Material {
public:
    virtual bool scatterLight(
            const Ray& rayIn, const HitRecord& hitRecord, Colour& attenuation, Ray& scattered
            ) const = 0;
};

#endif //RAYTRACINGINONEWEEKEND_MATERIALS_H
