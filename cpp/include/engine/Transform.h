#pragma once
#include "Vector.hpp"

class Transform
{
    private:
        Vector Position{(float)0, (float)0};
        double Rotation{0};
        Vector Scale{(float)1, (float)1};
    public:

    //////////////////
    // Constructors //
    //////////////////

        Transform();
        Transform(const Vector& position);
        Transform(const Vector& position, double rotation);

    /////////////////////////
    // Getters and Setters //
    /////////////////////////

        Vector getPosition() const;
        void setPosition(const Vector& position);

        double getRotation() const;
        void setRotation(double rotation);

        Vector getScale() const;
        void setScale(const Vector& scale);

    ///////////////
    // Behaviors //
    ///////////////

        void move(const Vector& vector);

    //////////////////////
    // Expected Methods //
    //////////////////////

        std::string toString() const;
};
