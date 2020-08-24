//
// Created by claul on 8/24/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_MATHFUNCTIONS_H
#define RAYTRACINGINONEWEEKEND_MATHFUNCTIONS_H

#include <random>

static const double randomDouble(const double min = 0.0, const double max = 1.0) {
    std::random_device rd;
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 randomGenerator(rd());
    return distribution(randomGenerator);
}

static const double clamp(const double x, const double min, const double max) {
    if (x < min) {
        return min;
    }
    else if (x > max) {
        return max;
    }
    return x;
}


#endif //RAYTRACINGINONEWEEKEND_MATHFUNCTIONS_H
