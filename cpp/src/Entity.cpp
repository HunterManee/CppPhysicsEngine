#include "engine/Entity.h"

//////////////////
// Constructors //
//////////////////


Entity::Entity(): transform{{}} {}
Entity::Entity(const Collider* c):
transform{{}}, collider{c->clone()} {}

Entity::Entity(const Transform& t):
transform(t) {}
Entity::Entity(const Transform& t, const Collider* c):
transform(t), collider{c->clone()} {}

/////////////////////////
// Getters and Setters //
/////////////////////////


Transform Entity::getTransform() const{
    return transform;
}

Collider* Entity::getCollider() const{
    return collider->clone();
}

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

