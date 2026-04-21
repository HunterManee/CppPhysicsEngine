#include "Point2.h"

struct Transform {

    Point2 Position;
    double Rotation;
    Point2 Scale;

    Transform();
    Transform(Point2 position);
    Transform(Point2 position, double rotation);
    Transform(Point2 position, double rotation, Point2 scale);

};
