#pragma once

#include "Transform.h"
#include "Collider.h"


class Entity {
    private:
        int ID;
        Transform transform{};
        Collider* collider{nullptr};

    public:
        Entity();
        Entity(int id);
        Entity(int id, const Collider* c);

        Entity(int id, const Transform& t);
        Entity(int id, const Transform& t, const Collider* c);

        Entity(const Entity& toCopy);

        int getID() const;
        Transform getTransform() const;
        Collider* getCollider() const;
        
        Entity* clone() const;
        std::string toString() const;
};