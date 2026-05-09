#include "engine/Entity.h"

//////////////////
// Constructors //
//////////////////


Entity::Entity():ID{-1}, transform{{}} {}
Entity::Entity(int id): ID{id}, transform{{}} {}
Entity::Entity(int id, const Collider* c):
ID{id}, transform{{}}, collider{c->clone()} {}

Entity::Entity(int id, const Transform& t):
ID{id}, transform(t) {}
Entity::Entity(int id, const Transform& t, const Collider* c):
ID{id}, transform(t), collider{c->clone()} {}

Entity::Entity(const Entity& toCopy):
ID{toCopy.ID}, transform{toCopy.transform}, collider{toCopy.collider->clone()} {}

/////////////////////////
// Getters and Setters //
/////////////////////////

int Entity::getID() const {
    return ID;
}

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
    output += "id: " + std::to_string(ID) + "\n";
    output += transform.toString();
    
    if(collider == nullptr) return output;
    output += collider->toString();


    return output;
}

Entity* Entity::clone() const {
    return new Entity(*this);
}

