#pragma once
#include "Vector.hpp"

class Rigidbody{

    private:
        Vector Velocity;
        double AngularVelocity;
        float Mass;

    public:
        Rigidbody();
        Rigidbody(const Vector velocity);
        Rigidbody(const Vector velocity, const double angularVelocity);
        Rigidbody(const Vector velocity, const double angularVelocity, const float mass);
        Rigidbody(const Rigidbody& toCopy);

        Vector getVelocity() const;
        void setVelocity(const Vector velocity);
        
        double getAngularVelocity() const;
        void setAngularVelocity(const double angularVelocity);

        float getMass() const;
        void setMass(const float mass);

        Rigidbody* clone() const;
        std::string to_string() const;
};

