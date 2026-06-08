#include "engine/CircleCollider.h"

CircleCollider::CircleCollider():
Collider{Circle}, Radius{Collider::Build_Radius} {}
CircleCollider::CircleCollider(float radius):
Collider{Circle, radius}, Radius{Collider::Build_Radius} {}
CircleCollider::CircleCollider(const CircleCollider& toCopy):
Collider{toCopy.Shape, toCopy.Build_Radius}, Radius{toCopy.Radius} {}

float CircleCollider::getRadius() const {
    return Radius;
}
void CircleCollider::setRadius(const float radius) {
    Radius = radius;
}

Collider* CircleCollider::clone() const {
    return new CircleCollider(*this);
}
std::string CircleCollider::to_string() const {
    std::string output;
    
    output += "--CircleCollider---------------------\n";
    output += "  L--> Radius: " + std::to_string(Radius) + "\n";

    return output;
}
