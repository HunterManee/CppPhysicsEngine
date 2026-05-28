#pragma once
#include "string"
#include "Random.hpp"

enum SHAPE{
    Circle,
    Polygon
};

class Collider{
    protected:
        SHAPE Shape;
        const float Min_Build_Radius{50};
        const float Max_Build_Radius{100};

    public:
        Collider(SHAPE shape): Shape(shape) {}
        virtual ~Collider() = default;

        SHAPE getShape() const {return Shape;}
        
        virtual Collider* clone() const = 0;
        virtual std::string  to_string() const = 0;
};