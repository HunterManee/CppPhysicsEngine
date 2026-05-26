#include "engine/Transform.h"

Transform::Transform():
Position{(float)0, (float)0}, Rotation{0}, Scale{(float)1, (float)1} {}
Transform::Transform(const Vector& position):
Position{position}, Rotation{0}, Scale{(float)1, (float)1} {}
Transform::Transform(const Vector& position, double rotation):
Position{position}, Rotation{rotation}, Scale{(float)1, (float)1} {}

Vector Transform::getPosition() const {
    return Position;
}
void Transform::setPosition(const Vector& position) {
    Position = position;
}

double Transform::getRotation() const {
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

std::string Transform::to_string() const {
    std::string output = "";
    output += "--Transform--------------------------\n";
    output += "  L--> Position: " + Position.to_string() + "\n";
    output += "  L--> Rotation: " + std::to_string(Rotation) + " Rads\n";
    output += "  L--> Scale:    " + Scale.to_string() + "\n";

    return output;
}
