#pragma once
#include <string>

#include "Random.hpp"

class Collider{
    public: 
        virtual ~Collider() = default;
        virtual std::string getShape() const = 0;
        virtual Collider* clone() const = 0;
        virtual std::string toString() const = 0;
};