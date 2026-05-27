#include "engine/Rigidbody.h"

Rigidbody::Rigidbody():
Velocity{{}}, AngularVelocity{0} {}
Rigidbody::Rigidbody(const Vector velocity):
Velocity{velocity}, AngularVelocity{0} {}
Rigidbody::Rigidbody(const Vector velocity, const double angularVelocity):
Velocity{velocity}, AngularVelocity{angularVelocity} {}
Rigidbody::Rigidbody(const Rigidbody& toCopy):
Velocity{toCopy.Velocity}, AngularVelocity{toCopy.AngularVelocity} {}

Vector Rigidbody::getVelocity() const {
    return Velocity;
}
void Rigidbody::setVelocity(const Vector velocity) {
    Velocity = velocity;
}

double Rigidbody::getAngularVelocity() const{
    return AngularVelocity;
}
void Rigidbody::setAngularVelocity(const double angularVelocity) {
    AngularVelocity = angularVelocity;
}

Rigidbody* Rigidbody::clone() const {
    return new Rigidbody(*this);
}
std::string Rigidbody::to_string() const {
    std::string output;

    output += "--Rigidbody--------------------------\n";
    output += "  L--> Velocity: " + Velocity.to_string() + "\n";
    output += "  L--> AngularVelocity: " + std::to_string(AngularVelocity) + "\n";

    return output;
}
