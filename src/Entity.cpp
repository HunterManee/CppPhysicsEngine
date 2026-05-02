#include "Entity.h"

//////////////////
// Constructors //
//////////////////


Entity::Entity(int id): ID{id}, transform{{}} {}
Entity::Entity(int id, const Collider* c):
ID{id}, transform{{}}, collider{c->clone()} {}

Entity::Entity(int id,const Transform& t):
ID{id}, transform(t) {}
Entity::Entity(int id, const Transform& t, const Collider* c):
ID{id}, transform(t), collider{c->clone()} {}

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

