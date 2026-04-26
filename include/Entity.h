#pragma once

#include "Transform.h"
#include "Collider.h"

class Entity {
    private:
        Transform transform{};
        Collider* collider{nullptr};
    public:
        Entity();
        Entity(const Transform& t);
        Entity(const Transform& t, Collider* c = nullptr);


        std::string toString() const;

};