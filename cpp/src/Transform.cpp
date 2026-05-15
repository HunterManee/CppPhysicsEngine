#include "engine/Transform.h"

//////////////////
// Constructors //
//////////////////


Transform::Transform() {}
Transform::Transform(const Vector& position):
Position{position} {}
Transform::Transform(const Vector& position, double rotation):
Position{position}, Rotation{rotation} {}

/////////////////////////
// Getters and Setters //
/////////////////////////


Vector Transform::getPosition() const{
    return Position; //returns a copy
}
void Transform::setPosition(const Vector& position) {
    Position = position;
}

double Transform::getRotation() const{
    return Rotation;
}
void Transform::setRotation(double rotation) {
    Rotation = rotation;
}

Vector Transform::getScale() const{
    return Scale;
}
void Transform::setScale(const Vector& scale) {
    Scale = scale; 
} 

///////////////
// Behaviors //
///////////////


void Transform::move(const Vector& vector) {
    setPosition(Position + vector);
}

//////////////////////
// Expected Methods //
//////////////////////


std::string Transform::toString() const{
    
    std::string output = "";
    output += "--Transform--------------------------\n";
    output += "  L--> Position: " + Position.to_string() + "\n";
    output += "  L--> Rotation: " + std::to_string(Rotation) + " Rads\n";
    output += "  L--> Scale:    " + Scale.to_string() + "\n";

    return output;
}

