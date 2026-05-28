#include "engine/CircleCollider.h"

CircleCollider::CircleCollider():
Collider{Circle}, Radius{Random::getRandomFloat(Min_Build_Radius, Max_Build_Radius)} {}
CircleCollider::CircleCollider(float radius):
Collider{Circle}, Radius{radius} {}
CircleCollider::CircleCollider(const CircleCollider& toCopy):
Collider{toCopy.Shape}, Radius{toCopy.Radius} {}

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
