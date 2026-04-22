#include <vector>

#include "Collider2.h"
#include "Point2.h"

struct PolygonCollider2 : public Collider2 {
    std::vector<Point2> Verticies;

    PolygonCollider2(const std::vector<Point2>& verticies);
};