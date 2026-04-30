#pragma once
#include <string>

#include "Random.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class Collider{
    public: 
        virtual ~Collider() = default;
        virtual void function() = 0;

        virtual Collider* clone() const = 0;
        virtual std::string toString() const = 0;
        virtual json serialize() const = 0;
};