#pragma once
#include "string"
#include "Random.hpp"

class Collider{

    protected:
        const float Min_Build_Radius{50};
        const float Max_Build_Radius{100};

    public:
        virtual ~Collider() = default;
        virtual Collider* clone() const = 0;
        virtual std::string  to_string() const = 0;
};