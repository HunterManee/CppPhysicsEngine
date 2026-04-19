
#include "Point.h"
#include "Vector2.h"

#include <cmath>

//Constructors
Vector2::Vector2(double magnitude, double theta):
Magnitude(magnitude), Theta(theta) {}
Vector2::Vector2(const Point& from, const Point& to):
Magnitude(from.distanceTo(to)), Theta(from.angleTo(to)) {}

//Overloaded Operators
Vector2 Vector2::operator+(const Vector2& vector2) const {
    double deltaX = getDeltaX() + vector2.getDeltaX();
    double deltaY = getDeltaY() + vector2.getDeltaY();
    
    double magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);
    double theta = atan2(deltaY, deltaX);

    return Vector2(magnitude, theta);
}
Vector2 Vector2::operator-(const Vector2& vector2) const {
    double deltaX = getDeltaX() - vector2.getDeltaX();
    double deltaY = getDeltaY() - vector2.getDeltaY();

    double magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);
    double theta = atan2(deltaY, deltaX);

    return Vector2(magnitude, theta);
}
Vector2 Vector2::operator*(const double scalar) const {
    double deltaX = getDeltaX() * scalar;
    double deltaY = getDeltaY() * scalar;
    
    double magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);
    double theta = atan2(deltaY, deltaX);

    return Vector2(magnitude, theta);
}

//Public Functions
double Vector2::getDeltaX() const {
    return Magnitude * cos(Theta);
}
double Vector2::getDeltaY() const {
    return Magnitude * sin(Theta);
}
Vector2 Vector2::normalize() const {
    return Vector2(1, Theta);
}