#pragma once
#include "Point2.h"

class Transform
{
    private:
        Point2 Position{0, 0};
        double Rotation{0};
        Point2 Scale{1,1};
    public:

    //////////////////
    // Constructors //
    //////////////////

        Transform();
        Transform(const Point2& position);
        Transform(const Point2& position, double rotation);

    /////////////////////////
    // Getters and Setters //
    /////////////////////////

        Point2 getPosition() const;
        void setPosition(const Point2& position);

        double getRotation() const;
        void setRotation(double rotation);

        Point2 getScale() const;
        void setScale(const Point2& scale);

    ///////////////
    // Behaviors //
    ///////////////

        void move(const Vector2& vector);

    //////////////////////
    // Expected Methods //
    //////////////////////

        std::string toString() const;
};
