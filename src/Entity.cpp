#include "Entity.h"

//////////////////
// Constructors //
//////////////////


Entity::Entity() {}
Entity::Entity(const Transform& t):
transform(t) {}


//////////////////////
// Expected Methods //
//////////////////////

std::string Entity::toString() const {
    std::string output = "";

    output += "Entity-------------------------------\n";
    output += transform.toString();
    return output;
}