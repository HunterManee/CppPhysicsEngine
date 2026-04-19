#pragma once //The header can only be used once

struct Point; //forward declaration


struct Vector2{
    double Magnitude;
    double Theta;

    Vector2(double magnitude, double theta);
    Vector2(const Point& from, const Point& to);

    double getDeltaX() const;
    double getDeltaY() const;

};
