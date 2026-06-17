#include "engine/Rigidbody.h"

Rigidbody::Rigidbody():
Velocity{{}}, AngularVelocity{0}, Mass{1} {}
Rigidbody::Rigidbody(const Vector velocity):
Velocity{velocity}, AngularVelocity{0}, Mass{1} {}
Rigidbody::Rigidbody(const Vector velocity, const double angularVelocity):
Velocity{velocity}, AngularVelocity{angularVelocity}, Mass{1} {}
Rigidbody::Rigidbody(const Vector velocity, const double angularVelocity, const float mass):
Velocity{velocity}, AngularVelocity{angularVelocity}, Mass{mass} {}
Rigidbody::Rigidbody(const Rigidbody& toCopy):
Velocity{toCopy.Velocity}, AngularVelocity{toCopy.AngularVelocity}, Mass{toCopy.Mass} {}

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

float Rigidbody::getMass() const {
    return Mass;
}
void Rigidbody::setMass(const float mass) {
    Mass = mass;
}

Rigidbody* Rigidbody::clone() const {
    return new Rigidbody(*this);
}
std::string Rigidbody::to_string() const {
    std::string output;

    output += "--Rigidbody--------------------------\n";
    output += "  L--> Velocity: " + Velocity.to_string() + "\n";
    output += "  L--> AngularVelocity: " + std::to_string(AngularVelocity) + "\n";
    output += "  L--> Mass: " + std::to_string(Mass) + "\n";

    return output;
}
