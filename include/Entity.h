#pragma once

#include "Transform.h"
#include "Collider.h"


class Entity {
    private:
        int ID;
        Transform transform{};
        Collider* collider{nullptr};

    public:
        Entity(int id);
        Entity(int id, const Collider* c);

        Entity(int id, const Transform& t);
        Entity(int id, const Transform& t, const Collider* c);

        Transform getTransform() const;
        Collider* getCollider() const;

        std::string toString() const;
};