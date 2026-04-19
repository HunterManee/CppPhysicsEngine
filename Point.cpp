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

//const Point& avoids copying the struct
//const at the end means the function doesn't modify the object
double Point::distanceTo(const Point& other) const {
    double deltaX = other.X - X;
    double deltaY = other.Y - Y;
    return sqrt(deltaX * deltaX + deltaY * deltaY);
}

double Point::angleTo(const Point& other) const {
    double deltaX = other.X - X;
    double deltaY = other.Y - Y;
    return atan2(deltaY, deltaX);
}