#include "Point.h"
#include "Vector2.h"

#include <cmath>

Vector2::Vector2(double magnitude, double theta):
Magnitude(magnitude), Theta(theta) {}

Vector2::Vector2(const Point& from, const Point& to):
Magnitude(from.distanceTo(to)), Theta(from.angleTo(to)) {}


double Vector2::getDeltaX() const {
    return Magnitude * cos(Theta);
}
double Vector2::getDeltaY() const {
    return Magnitude * sin(Theta);
}