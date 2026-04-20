#include "Shape2.h"


Shape2::Shape2():
Position{Point2{}}, Rotation{0}, Scale{1}{}

Shape2::Shape2(const Point2& position):
Position{position}, Rotation{0}, Scale{1} {}