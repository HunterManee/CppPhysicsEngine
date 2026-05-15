#include "engine/CircleCollider.h"
#include <iostream>

//Constructors

CircleCollider::CircleCollider(){
    Radius = Random::getRandomDouble(MinRandRadius, MaxRandRadius);
};

CircleCollider::CircleCollider(double radius):
Radius{radius} {
    Radius = radius;
};

CircleCollider::CircleCollider(const CircleCollider& toCopy) {
    *this = toCopy;
}

//Getters and Setters

double CircleCollider::getRadius() const{
    return Radius;
}

void CircleCollider::setRadius(double radius) {
    Radius = radius;
}

std::string CircleCollider::getShape() const {
    return "circle";
}

//Expected Variables
Collider* CircleCollider::clone() const{
    return new CircleCollider(*this);
}

std::string CircleCollider::toString() const {    
    std::string output;
    
    output += "--CircleCollider---------------------\n";
    output += "  L--> Radius: " + std::to_string(Radius) + "\n";

    return output;
}