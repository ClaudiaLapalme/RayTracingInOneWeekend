//
// Created by claul on 8/21/2020.
//

#include "../../Headers/Containers/CollidableList.h"

bool CollidableList::hit(const Ray &ray, const double tMin, const double tMax, HitRecord &hitRecord) const {
    HitRecord tempHitRecord{};
    auto closestHitSoFar = tMax;
    auto hasHit = false;

    for (const auto& collidable : collidables) {
        if (collidable->hit(ray, tMin, closestHitSoFar, tempHitRecord)) {
            hasHit = true;
            closestHitSoFar = tempHitRecord.t;
            hitRecord = tempHitRecord;
        }
    }
    return hasHit;
}
