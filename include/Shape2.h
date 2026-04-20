#pragma once
#include "Point2.h"

struct Shape2 {
    Point2 Position;
    double Rotation;
    double Scale;

    Shape2();
    Shape2(const Point2& position);
};