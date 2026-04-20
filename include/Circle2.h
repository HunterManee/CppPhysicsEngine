#include "Shape2.h"

struct Circle2: public Shape2{
    double Radius;

    Circle2(const Point2& position, double radius = 10);
    Circle2(const Point2& position, double rotation, double radius = 10);

};