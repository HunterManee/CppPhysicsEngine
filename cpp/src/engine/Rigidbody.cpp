#include "engine/Rigidbody.h"

Rigidbody::Rigidbody():
Velocity{{}} {}
Rigidbody::Rigidbody(const Vector velocity):
Velocity{velocity} {}
Rigidbody::Rigidbody(const Rigidbody& toCopy):
Velocity{toCopy.Velocity} {}

Vector Rigidbody::getVelocity() const {
    return Velocity;
}
void Rigidbody::setVelocity(const Vector velocity) {
    Velocity = velocity;
}

Rigidbody* Rigidbody::clone() const {
    return new Rigidbody(*this);
}
std::string Rigidbody::to_string() const {
    std::string output;

    output += "--Rigidbody--------------------------\n";
    output += "  L--> Velocity: " + Velocity.to_string() + "\n";

    return output;
}
