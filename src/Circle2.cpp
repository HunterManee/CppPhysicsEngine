#include "Circle2.h"

Circle2::Circle2(const Point2& position, double radius):
Shape2{position}, Radius(radius) {}

Circle2::Circle2(const Point2& position, double rotation, double radius):
Shape2{position, rotation}, Radius{radius} {}