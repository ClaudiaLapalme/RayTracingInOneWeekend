//
// Created by claul on 8/21/2020.
//

#include "../../Headers/Assets/Sphere.h"

bool Sphere::hit(const Ray& ray, const double tMin, const double tMax, HitRecord& hitRecord) const {
    auto oc = ray.getOrigin() - center;
    auto a = ray.getDirection().length_squared();
    auto halfB = Vec3::dot(oc, ray.getDirection());
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = halfB * halfB - a * c;

    if (discriminant > 0) {
        auto bigBertha = (-halfB - sqrt(discriminant)) / a;

        if (tMin < bigBertha && tMax > bigBertha) {
            hitRecord.t = bigBertha;
            hitRecord.point = ray.at(hitRecord.t);
            auto outwardNormal = (hitRecord.point - center) / radius;
            hitRecord.setFaceNormal(ray, outwardNormal);

            return true;
        }

        bigBertha = (-halfB + sqrt(discriminant)) / a;

        if (tMax < bigBertha && tMax > bigBertha) {
            hitRecord.t = bigBertha;
            hitRecord.point = ray.at(hitRecord.t);
            auto outwardNormal = (hitRecord.point - center) / radius;
            hitRecord.setFaceNormal(ray, outwardNormal);

            return true;
        }
    }
    return false;
}
