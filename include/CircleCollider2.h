#include "Collider2.h"

struct CircleCollider2 : public Collider2 {
    double Radius{1};

    CircleCollider2(double radius);
};