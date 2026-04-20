#include "Point2.h"
#include "Vector2.h"

#include <cmath>


Point2::Point2(): 
X(0), Y(0) {}

Point2::Point2(double x, double y):
X(x), Y(y) {}

Point2 Point2::operator+(const Vector2& vector2) const{
    return Point2(
        X + vector2.getDeltaX(), 
        Y + vector2.getDeltaY()
    );
}

Point2 Point2::operator-(const Vector2& vector2) const{
    return Point2(
        X - vector2.getDeltaX(), 
        Y - vector2.getDeltaY()
    );
}
Vector2 Point2::operator-(const Point2& to) const{
    double deltaX = to.X - X;
    double deltaY = to.Y - Y;

    double magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);
    double theta = atan2(deltaY, deltaX);

    return Vector2(magnitude, theta);
}