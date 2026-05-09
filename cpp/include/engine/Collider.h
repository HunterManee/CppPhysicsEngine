#pragma once
#include <string>

#include "Random.h"

class Collider{
    public: 
        virtual ~Collider() = default;
        virtual std::string getShape() const = 0;
        virtual Collider* clone() const = 0;
        virtual std::string toString() const = 0;
};