#pragma once

#include "Transform.h"

class Entity {
    private:
        Transform transform{};

    public:
        Entity();
        Entity(const Transform& t);


        std::string toString() const;

};