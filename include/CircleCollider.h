#pragma once
#include "Collider.h"

class CircleCollider : public Collider {
    private:
        double Radius{1};

    public:

        static constexpr double MinRandRadius{1};
        static constexpr double MaxRandRadius{20};

        CircleCollider();
        CircleCollider(double radius);
        CircleCollider(const CircleCollider& toCopy);

        void function() override;
        Collider* clone() const override;
        std::string toString() const override;
        
};