#include "Polygon2.h"

Polygon2::Polygon2(const Point2& position, const std::vector<Point2>& verticies):
Shape2{position}, Verticies{verticies} {}

Polygon2::Polygon2(const Point2& position, double rotation, const std::vector<Point2>& verticies):
Shape2{position, rotation}, Verticies{verticies} {}