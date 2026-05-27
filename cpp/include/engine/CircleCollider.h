#pragma once
#include "Collider.hpp"

class CircleCollider : public Collider {

    private:
        float Radius;
    
    public:
        CircleCollider();
        CircleCollider(float radius);
        CircleCollider(const CircleCollider& toCopy);

        float getRadius() const;
        void setRadius(const float radius);

        Collider* clone() const override;
        std::string to_string() const override;

};