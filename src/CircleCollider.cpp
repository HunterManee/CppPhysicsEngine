#include "CircleCollider.h"
#include <iostream>

CircleCollider::CircleCollider(){
    Random randNum;
    Radius = randNum.getRandomDouble(1, 5);
};

CircleCollider::CircleCollider(double radius):
Radius{radius} {
    Random randNum;
    radius = randNum.getRandomDouble(1, 5);
};

CircleCollider::CircleCollider(const CircleCollider& toCopy) {
    *this = toCopy;
}

void CircleCollider::function() {
    std::cout << "From Circle Collider" << std::endl;
} 

Collider* CircleCollider::clone() const{
    return new CircleCollider(*this);
}

std::string CircleCollider::toString() const {    
    std::string output;
    
    output += "--CircleCollider---------------------\n";
    output += "  L--> Radius: " + std::to_string(Radius);

    return output;

}