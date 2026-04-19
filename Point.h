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

    //Public Functions
    double distanceTo(const Point& point) const;
    double angleTo(const Point& point) const;

};