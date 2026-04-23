#include <iostream>
#include <cmath>
using namespace std;

#include "Point2.h"
#include "Vector2.h"


int main() {

    // Point2 Testing
    // Default Constructor test
    // Point2 p1{};
    // cout << p1.toString();

    // Construct w/ values test
    // Point2 p1{1, 1};
    // cout << p1.toString();

    // Vector2 Testing
    // Default Constructor test;
    // Vector2 v1{};
    // cout << v1.toString();

    // Construct w/ values test
    // Vector2 v1{1, atan2(1,0)};
    // cout << v1.toString();

    // Point2 Overloaded Operator Test

    // Point - Point = Vector
    // Point2 p1{};
    // Point2 p2{0,1};
    // Vector2 v1 = p2 - p1;
    // cout << p2.toString() << " - " << p1.toString() << " = " << v1.toString();

    // Point + Vector = Point
    // Point2 p1{};
    // Vector2 v1{1, atan2(1,1)};
    // Point2 p2 = p1 + v1;
    // cout << p1.toString() << " + " << v1.toString() << " = " << p2.toString();

    // Point - Vector = Point
    // Point2 p1{};
    // Vector2 v1{1, atan2(1,1)};
    // Point2 p2 = p1 - v1;
    // cout << p1.toString() << " - " << v1.toString() << " = " << p2.toString();

}