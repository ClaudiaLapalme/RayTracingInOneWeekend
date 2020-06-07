//
// Created by claul on 6/7/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_VEC3_H
#define RAYTRACINGINONEWEEKEND_VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
private:
    double e[3];
public:

    vec3() = default;
    vec3(double v1, double v2, double v3) : e{v1, v2, v3} {};

    double x() { return e[0]; };
    double y() { return e[1]; };
    double z() { return e[2]; };

    vec3 operator-() { return vec3(-e[0], -e[1], -e[2]); };

    double operator[](int i) { return e[i]; };

    vec3& operator+=(const vec3& vec) {
        this->e[0] += vec.e[0];
        this->e[1] += vec.e[1];
        this->e[2] += vec.e[2];
        return *this;
    }

    vec3& operator*=(const double val) {
        this->e[0] *= val;
        this->e[1] *= val;
        this->e[2] *= val;
        return *this;
    }

    vec3& operator/=(const double val) {
        return *this *= 1 / val;
    }

    double length_squared() {
        return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]);
    }

    double length() {
        return std::sqrt(length_squared());
    }

    // vec3 Utility Functions

    friend inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
    }

    friend inline vec3 operator+(const vec3 &u, const vec3 &v) {
        return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
    }

    friend inline vec3 operator-(const vec3 &u, const vec3 &v) {
        return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
    }

    friend inline vec3 operator*(const vec3 &u, const vec3 &v) {
        return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
    }

    friend inline vec3 operator*(double t, const vec3 &v) {
        return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
    }

    friend inline vec3 operator*(const vec3 &v, double t) {
        return t * v;
    }

    friend inline vec3 operator/(vec3 v, double t) {
        return (1/t) * v;
    }

    inline double dot(const vec3 &u, const vec3 &v) {
        return u.e[0] * v.e[0]
               + u.e[1] * v.e[1]
               + u.e[2] * v.e[2];
    }

    inline vec3 cross(const vec3 &u, const vec3 &v) {
        return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                    u.e[2] * v.e[0] - u.e[0] * v.e[2],
                    u.e[0] * v.e[1] - u.e[1] * v.e[0]);
    }

    inline vec3 unit_vector(vec3 v) {
        return v / v.length();
    }
};

using point3 = vec3;
using colour = vec3;

#endif //RAYTRACINGINONEWEEKEND_VEC3_H
