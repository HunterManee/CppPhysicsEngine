#pragma once
#include "cmath"
#include "string"

struct Vector {

    float i, j;

    Vector(float i = 0, float j = 0):
    i{i}, j{j} {}
    Vector(float magnitude, double theta):
    i{magnitude * (float)std::cos(theta)},
    j{magnitude * (float)std::sin(theta)} {}


    Vector operator+ (const Vector other) const{
        return Vector(i + other.i, j + other.j);
    }
    Vector operator- (const Vector other) const{
        return Vector(i - other.i, j - other.j);
    }
    Vector operator* (const float scalar) const{
        return Vector(i * scalar, j * scalar);
    }
    Vector operator/ (const float scalar) const{
        return Vector(i / scalar, j / scalar);
    }

    float magnitude() const {
        return sqrt(i * i + j * j);
    }
    float theta() const {
        return atan2(j, i);
    }
    Vector normalize() const {
        float t = theta();
        return Vector(std::cos(t), std::sin(t));
    }
    Vector rotate(const double dTheta) const {
        return Vector{magnitude(), theta() + dTheta};
    }

    std::string to_string() const{
        std::string i_component = std::to_string((int)(i * 100) / 100.0);
        std::string j_component = std::to_string((int)(j * 100) / 100.0);
        std::string output = "(" + i_component + " ," + j_component + ")";
        return output;
    }
};

inline float dot(Vector a, Vector b) {
    return a.i * b.i + a.j * b.j;
}
inline float cross(Vector a, Vector b) {
    return a.i * b.j - a.j * b.i;
}