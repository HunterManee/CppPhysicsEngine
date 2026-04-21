#pragma once //The header can only be used once

struct Vector2; //forward declaration

struct Point2 {
    double X;
    double Y;

    //Constuctor
    Point2(double x = 0, double y = 0);

    //Overloaded Operators
    Point2 operator+(const Vector2& vector2) const;
    Point2 operator-(const Vector2& vector2) const;

    //Creating a vector from - to
    Vector2 operator-(const Point2& point) const;
    

};