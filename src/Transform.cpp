#include "Transform.h"

//////////////////
// Constructors //
//////////////////


Transform::Transform() {}
Transform::Transform(const Point2& position):
Position{position} {}
Transform::Transform(const Point2& position, double rotation):
Position{position}, Rotation{rotation} {}

/////////////////////////
// Getters and Setters //
/////////////////////////


Point2 Transform::getPosition() const{
    return Position; //returns a copy
}
void Transform::setPosition(const Point2& position) {
    Position = position;
}

double Transform::getRotation() const{
    return Rotation;
}
void Transform::setRotation(double rotation) {
    Rotation = rotation;
}

Point2 Transform::getScale() const{
    return Scale;
}
void Transform::setScale(const Point2& scale) {
    Scale = scale; 
} 

///////////////
// Behaviors //
///////////////


void Transform::move(const Vector2& vector) {
    setPosition(Position + vector);
}

//////////////////////
// Expected Methods //
//////////////////////


std::string Transform::toString() const{
    return "Position: " + Position.toString() + "\n" +
           "Rotation: " + std::to_string(Rotation) + " Rads\n" +
           "Scale:    " + Scale.toString() + "\n";
}
