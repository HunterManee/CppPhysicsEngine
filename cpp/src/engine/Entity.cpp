#include "engine/Entity.h"

Entity::Entity(signed int id):
ID{id}, transform{}, collider{nullptr}, rigidbody{nullptr} {}
Entity::Entity(signed int id, const Collider* c):
ID{id}, transform{}, collider{c->clone()}, rigidbody{nullptr} {}
Entity::Entity(signed int id, const Collider* c, const Rigidbody* r):
ID{id}, transform{}, collider{c->clone()}, rigidbody{r->clone()} {}

Entity::Entity(signed int id, const Transform& t):
ID{id}, transform{t}, collider{nullptr}, rigidbody{nullptr} {}
Entity::Entity(signed int id, const Transform& t, const Collider* c):
ID{id}, transform{t}, collider{c->clone()}, rigidbody{nullptr} {}
Entity::Entity(signed int id, const Transform& t, const Collider* c, const Rigidbody* r):
ID{id}, transform{t}, collider{c->clone()}, rigidbody{r->clone()} {}

Entity::Entity(const Entity& toCopy):
ID{toCopy.ID}, transform{toCopy.transform}, collider{toCopy.collider->clone()}, rigidbody{toCopy.rigidbody->clone()} {}

Entity::~Entity(){
    if(collider != nullptr) {
        delete collider;
        collider = nullptr;
    }
        if(rigidbody != nullptr) {
        delete rigidbody;
        rigidbody = nullptr;
    }
}

signed int Entity::getId() const{
    return ID;
}
Transform Entity::getTransform() const{
    return transform;
}
Collider* Entity::getNewCollider() const{
    return collider->clone();
}
Rigidbody* Entity::getNewRigidbody() const{
    return rigidbody->clone();
}

void Entity::move(const Vector velocity) {
    Vector nextPosition = transform.getPosition() + velocity;
    transform.setPosition(nextPosition);
    rigidbody->setVelocity(velocity);
}

Entity* Entity::clone() const{
    return new Entity(*this);
}
std::string Entity::to_string() const {
    std::string output = "";

    output += "Entity-------------------------------\n";
    output += "id: " + std::to_string(ID) + "\n";
    output += transform.to_string();
    
    if(collider != nullptr) output += collider->to_string();
    if(rigidbody != nullptr) output += rigidbody->to_string();

    return output;
}
