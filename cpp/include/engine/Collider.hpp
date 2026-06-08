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
        
        float Build_Radius;
        const float Min_Build_Radius{50};
        const float Max_Build_Radius{100};

    public:
        Collider(SHAPE shape): 
        Shape(shape) {
            Build_Radius = Random::getRandomFloat(Min_Build_Radius, Max_Build_Radius);
        }
        Collider(SHAPE shape, float buildRadius):
        Shape(shape), Build_Radius(buildRadius) {}
        virtual ~Collider() = default;

        SHAPE getShape() const {return Shape;}
        float getBuildRadius() const {return Build_Radius;}

        virtual Collider* clone() const = 0;
        virtual std::string to_string() const = 0;
};