#include "Point.h"
#include "Vector2.h"

#include <cmath>


Point::Point(double x, double y):
X(x), Y(y) {}

Point Point::operator+(const Vector2& vector2) const{
    return Point(
        X + vector2.getDeltaX(), 
        Y + vector2.getDeltaY()
    );
}

Point Point::operator-(const Vector2& vector2) const{
    return Point(
        X - vector2.getDeltaX(), 
        Y - vector2.getDeltaY()
    );
}
Vector2 Point::operator-(const Point& to) const{
    double deltaX = to.X - X;
    double deltaY = to.Y - Y;

    double magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);
    double theta = atan2(deltaY, deltaX);

    return Vector2(magnitude, theta);
}