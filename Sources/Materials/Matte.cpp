//
// Created by claul on 8/25/2020.
//

#include "../../Headers/Materials/Matte.h"

bool Matte::scatterLight(const Ray &rayIn, const HitRecord& hitRecord, Colour &attenuation, Ray &scattered) const {
    Vec3 scatterDirection = hitRecord.normal + Vec3::randomUnitVector();
    scattered = Ray(hitRecord.point, scatterDirection);
    attenuation = albedo;
    return true;
}
