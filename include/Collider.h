#pragma once
#include <string>

class Collider{
    public: 
        virtual ~Collider() = default;
        virtual void function() = 0;
        virtual Collider* clone() const = 0;
        virtual std::string toString() const = 0;
};