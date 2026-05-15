#pragma once

#include <iostream>

struct Vector {

    float i, j;

    Vector(float i = 0, float j = 0):
    i{i}, j{j} {}
    Vector(float magnitude, double theta):
    i{(float)(magnitude * cos(theta))}, j{(float)(magnitude * sin(theta))} {}

    Vector operator* (const float scaler) const {
        return Vector {i * scaler, j * scaler};
    }
    Vector operator/ (const float scaler) const {
        return Vector{i / scaler, j / scaler};
    }
    Vector operator+ (const Vector other) const {
        return Vector{i + other.i, j + other.j};
    }
    Vector operator- (const Vector other) const {
        return Vector{i - other.i, j - other.j};
    }

    float magnitude() const {
        return sqrt( i * i + j * j);
    }
    double theta() const {
        return atan2(j , i);
    }
    Vector rotate(const double dTheta) const {
        return Vector{magnitude(), theta() + dTheta};
    }
    
    Vector normailze() const {
        double t = theta();
        return Vector(cos(t), sin(t));
    }

    std::string to_string() const {
        std::string i_component = std::to_string((int)(i * 100) / 100.0);
        std::string j_component = std::to_string((int)(j * 100) / 100.0);
        std::string output = "(" + std::to_string(i) +" ,"+ std::to_string(j) + " )";
        
        return output;
    }

};

static float dot(const Vector a, const Vector b) {
    return a.i * b.i + a.j * b.j;
}
static float cross(const Vector a, const Vector b) {
    return a.i * b.j - a.j * b.i;
}


