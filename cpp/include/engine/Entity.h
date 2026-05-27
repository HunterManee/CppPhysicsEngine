#pragma once

#include "Transform.h"
#include "Collider.hpp"
#include "Rigidbody.h"

class Entity{
    
    private:
        const signed int ID;
        Transform transform;
        Collider* collider;
        Rigidbody* rigidbody;

    public:
        Entity(signed int id = 0);
        Entity(signed int id, const Collider* c);
        Entity(signed int id, const Collider* c, const Rigidbody* r);

        Entity(signed int id, const Transform& t);
        Entity(signed int id, const Transform& t, const Collider* c);
        Entity(signed int id, const Transform& t, const Collider* c, const Rigidbody* r);

        Entity(const Entity& toCopy);
        ~Entity();

        signed int getId() const;
        Transform getTransform() const;
        Collider* getNewCollider() const;
        Rigidbody* getNewRigidbody() const;

        void move();

        Entity* clone() const;
        std::string to_string() const;

};