#pragma once //The header can only be used once

struct Vector2; //forward declaration

struct Point {
    double X;
    double Y;

    //Constuctor
    Point(double x, double y);

    //Overloaded Operators
    Point operator+(const Vector2& vector2) const;
    Point operator-(const Vector2& vector2) const;

    //Creating a vector from to points
    Vector2 operator-(const Point& point) const;
    

};