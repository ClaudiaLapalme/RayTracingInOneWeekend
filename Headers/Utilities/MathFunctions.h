//
// Created by claul on 8/24/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_MATHFUNCTIONS_H
#define RAYTRACINGINONEWEEKEND_MATHFUNCTIONS_H

#include <random>

static constexpr double pi = 3.1415926535897932385;
static std::random_device rd;
static std::mt19937 randomGenerator(rd());

inline const double randomDouble(const double min = 0.0, const double max = 1.0) {
    static std::random_device rd;
    static std::mt19937 randomGenerator(rd());
    static std::uniform_real_distribution<double> distribution(min, max);
    return distribution(randomGenerator);
}

inline const double clamp(const double x, const double min, const double max) {
    if (x < min) {
        return min;
    }
    else if (x > max) {
        return max;
    }
    return x;
}

inline const double degrees2radians(const double degrees) {
    return degrees * pi / 180.0;
}


#endif //RAYTRACINGINONEWEEKEND_MATHFUNCTIONS_H
