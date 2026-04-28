#pragma once
#include "Collider.h"

class CircleCollider : public Collider {
    private:
        double Radius{1};
        const double MinRandRadius{1};
        const double MaxRandRadius{20};
        
    public:
        CircleCollider();
        CircleCollider(double radius);
        CircleCollider(const CircleCollider& toCopy);

        void function() override;
        Collider* clone() const override;
        std::string toString() const override;
        
};