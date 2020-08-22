//
// Created by claul on 8/21/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_COLLIDABLELIST_H
#define RAYTRACINGINONEWEEKEND_COLLIDABLELIST_H

#include "../Assets/Collidables.h"

#include <memory>
#include <vector>

class CollidableList : public Collidables {
public:
    CollidableList() = default;
    CollidableList(std::shared_ptr<Collidables> collidable) { add(collidable); }
    CollidableList(std::vector<std::shared_ptr<Collidables>> collidables) : collidables(collidables) {};

    void clear() { collidables.clear(); }
    void add(std::shared_ptr<Collidables> collidable) { collidables.push_back(collidable); }

    virtual bool hit(const Ray& ray, const double tMin, const double tMax, HitRecord& hitRecord) const override;

private:
    std::vector<std::shared_ptr<Collidables>> collidables;
};


#endif //RAYTRACINGINONEWEEKEND_COLLIDABLELIST_H
