#pragma once
#include "Vector.hpp"

class Rigidbody{

    private:
        Vector Velocity;

    public:
        Rigidbody();
        Rigidbody(const Vector velocity);
        Rigidbody(const Rigidbody& toCopy);

        Vector getVelocity() const;
        void setVelocity(const Vector velocity);
        
        Rigidbody* clone() const;
        std::string to_string() const;
};

