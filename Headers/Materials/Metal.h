//
// Created by claul on 8/25/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_METAL_H
#define RAYTRACINGINONEWEEKEND_METAL_H

#include "Materials.h"
#include "../Utilities/Vec3.h"
#include "../Utilities/Ray.h"
#include "../Utilities/HitRecord.h"

/**
 * The metal class reflects light in a mirrored fashion.
 * The angle of the vector in (from the normal) will be the same as the angle of the vector out
 */
class Metal : public Material {
public:
    Metal(const Colour& alpha) : albedo(alpha) {};
    virtual bool scatterLight(
            const Ray& rayIn, const HitRecord& hitRecord, Colour& attenuation, Ray& scattered
    ) const override;

private:
    Colour albedo;
};


#endif //RAYTRACINGINONEWEEKEND_METAL_H
