#pragma once
#include "Collider.h"

class CircleCollider : public Collider {
    private:
        double Radius{1};
        
    public:
        CircleCollider(double radius = 0);
        CircleCollider(const CircleCollider& toCopy);

        void function() override;
        Collider* clone() const override;
        std::string toString() const override;
        
};