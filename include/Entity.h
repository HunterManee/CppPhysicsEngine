#pragma once

#include "Transform.h"
#include "Collider.h"

class Entity {
    private:
        Transform transform{};
        Collider* collider{nullptr};
    public:
        Entity();
        Entity(const Collider* c);

        Entity(const Transform& t);
        Entity(const Transform& t, const Collider* c);


        std::string toString() const;

};