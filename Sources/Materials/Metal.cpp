//
// Created by claul on 8/25/2020.
//

#include "../../Headers/Materials/Metal.h"

bool Metal::scatterLight(const Ray &rayIn, const HitRecord &hitRecord, Colour &attenuation, Ray &scattered) const {
    Vec3 reflected = Vec3::reflect(Vec3::unit_vector(rayIn.getDirection()), hitRecord.normal);
    scattered = Ray(hitRecord.point, reflected);
    attenuation = albedo;
    return Vec3::dot(scattered.getDirection(), hitRecord.normal) > 0;
}
