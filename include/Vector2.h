#pragma once //The header can only be used once


struct Vector2{
    double Magnitude;
    double Theta;

    //Constructors
    Vector2(double magnitude = 1, double theta = 0);

    //Overloaded Operators
    Vector2 operator+(const Vector2& vector2) const;
    Vector2 operator-(const Vector2& vector2) const;
    Vector2 operator*(const double scalar) const;

    //Public Functions
    double getDeltaX() const;
    double getDeltaY() const;
    Vector2 normalize() const;
};
