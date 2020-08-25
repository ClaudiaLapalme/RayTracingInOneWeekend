//
// Created by claul on 8/25/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_MATTE_H
#define RAYTRACINGINONEWEEKEND_MATTE_H

#include "Materials.h"
#include "../Utilities/Vec3.h"

/**
 * The matte material uses lambertian math to produce the desired finish
 */
class Matte : public Material {
public:
    Matte(const Colour& alpha) : albedo(alpha) {};
    virtual bool scatterLight(
            const Ray& rayIn, const HitRecord& hitRecord, Colour& attenuation, Ray& scattered
            ) const override;

private:
    Colour albedo; // measure of how much light is reflected
};


#endif //RAYTRACINGINONEWEEKEND_MATTE_H
