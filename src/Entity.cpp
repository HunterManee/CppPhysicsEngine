#include "Entity.h"

//////////////////
// Constructors //
//////////////////


Entity::Entity() {}
Entity::Entity(const Collider* c):
collider{c->clone()} {}

Entity::Entity(const Transform& t):
transform(t) {}
Entity::Entity(const Transform& t, const Collider* c):
transform(t), collider{c->clone()} {}


//////////////////////
// Expected Methods //
//////////////////////

std::string Entity::toString() const {
    std::string output = "";

    output += "Entity-------------------------------\n";
    output += transform.toString();
    
    if(collider == nullptr) return output;
    output += collider->toString();


    return output;
}