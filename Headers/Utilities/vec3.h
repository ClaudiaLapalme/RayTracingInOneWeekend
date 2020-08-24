//
// Created by claul on 6/7/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_VEC3_H
#define RAYTRACINGINONEWEEKEND_VEC3_H

#include "MathFunctions.h"

#include <cmath>
#include <iostream>

class Vec3 {
private:
    double e[3];
public:

    Vec3() = default;
    Vec3(double v1, double v2, double v3) : e{v1, v2, v3} {};

    double x() { return e[0]; };
    double y() { return e[1]; };
    double z() { return e[2]; };

    Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); };

    double operator[](int i) { return e[i]; };

    Vec3& operator+=(const Vec3& vec) {
        this->e[0] += vec.e[0];
        this->e[1] += vec.e[1];
        this->e[2] += vec.e[2];
        return *this;
    }

    Vec3& operator*=(const double val) {
        this->e[0] *= val;
        this->e[1] *= val;
        this->e[2] *= val;
        return *this;
    }

    Vec3& operator/=(const double val) {
        return *this *= 1 / val;
    }

    double length_squared() const {
        return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]);
    }

    double length() const {
        return std::sqrt(length_squared());
    }

    // Vec3 Utility Functions

    friend inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }

    friend inline Vec3 operator+(const Vec3 &u, const Vec3 &v) {
        return Vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
    }

    friend inline Vec3 operator-(const Vec3 &u, const Vec3 &v) {
        return Vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
    }

    friend inline Vec3 operator*(const Vec3 &u, const Vec3 &v) {
        return Vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
    }

    friend inline Vec3 operator*(double t, const Vec3 &v) {
        return Vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
    }

    friend inline Vec3 operator*(const Vec3 &v, double t) {
        return t * v;
    }

    friend inline Vec3 operator/(Vec3 v, double t) {
        return (1/t) * v;
    }

    inline static double dot(const Vec3 &u, const Vec3 &v) {
        return u.e[0] * v.e[0]
               + u.e[1] * v.e[1]
               + u.e[2] * v.e[2];
    }

    inline Vec3 cross(const Vec3 &u, const Vec3 &v) {
        return Vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                    u.e[2] * v.e[0] - u.e[0] * v.e[2],
                    u.e[0] * v.e[1] - u.e[1] * v.e[0]);
    }

    inline static Vec3 unit_vector(const Vec3& v) {
        return v / v.length();
    }

    static Vec3 random(const double min = 0, const double max = 1) {
        return Vec3(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
    }

    static Vec3 randomInUnitSphere() {
        while (true) {
            auto p = random(-1, 1);
            if (p.length_squared() < 1) {
                return p;
            }
        }
    }
};

using Point3 = Vec3;
using Colour = Vec3;

#endif //RAYTRACINGINONEWEEKEND_VEC3_H
