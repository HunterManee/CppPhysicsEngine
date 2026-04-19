#include "Point.h"

struct Vector2{
    double Magnitude;
    double Theta;

    Vector2(double magnitude, double theta);
    Vector2(const Point& from, const Point& to);

    double getDeltaX() const {}
    double getDeltaY() const {}

};
