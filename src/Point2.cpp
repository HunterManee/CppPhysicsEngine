#include "Point2.h"
#include "Vector2.h"

#include <cmath>


Point2::Point2(double x, double y):
X{x}, Y{y} {}


Point2 Point2::operator+(const Vector2& vector2) const{
    return { X + vector2.getDeltaX(), Y + vector2.getDeltaY() };
}
Point2 Point2::operator-(const Vector2& vector2) const{
    return { X - vector2.getDeltaX(), Y - vector2.getDeltaY() };
}
Vector2 Point2::operator-(const Point2& from) const{
    double deltaX = X - from.X;
    double deltaY = Y - from.Y;

    double magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);
    double theta = atan2(deltaY, deltaX);

    return { magnitude, theta };
}

std::string Point2::toString() const {
    return "(" + std::to_string(X) +" ,"+ std::to_string(Y) + " )";
}