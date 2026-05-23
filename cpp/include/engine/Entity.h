#pragma once

#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

class Entity {
    private:
        int ID;
        Transform transform{};
        Collider* collider{nullptr};
        Rigidbody* rigidbody{nullptr};

    public:
        Entity();
        Entity(int id);
        Entity(int id, const Collider* c);
        Entity(int id, const Collider* c, const Rigidbody* r);

        Entity(int id, const Transform& t);
        Entity(int id, const Transform& t, const Collider* c);
        Entity(int id, const Transform& t, const Collider* c, const Rigidbody* r);

        Entity(const Entity& toCopy);

        ~Entity();

        int getID() const;
        Transform& getTransform();
        const Transform getTransform() const;
        Collider* getCollider() const;
        Rigidbody* getRigidbody() const;


        std::string to_string() const;
        Entity* clone() const;

};