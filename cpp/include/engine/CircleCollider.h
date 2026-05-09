#pragma once
#include "Collider.h"

class CircleCollider : public Collider {
    private:
        double Radius{1};

    public:

        static constexpr double MinRandRadius{50};
        static constexpr double MaxRandRadius{100};

        CircleCollider();
        CircleCollider(double radius);
        CircleCollider(const CircleCollider& toCopy);

        double getRadius() const;
        void setRadius(double radius);
        
        std::string getShape() const override;
        Collider* clone() const override;
        std::string toString() const override;

};