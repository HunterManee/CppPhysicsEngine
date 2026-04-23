#include <iostream>
#include <cmath>
using namespace std;

#include "Point2.h"
#include "Vector2.h"


void PointConstructorTest();
void VectorConstructorTest();
void PointOverloadOperatorTest();
void VectorOverloadOperatorTest();

int main() {

    // Constructor Tests
    // PointConstructorTest();
    // VectorConstructorTest();

    // Operation Overload Tests
    // PointOverloadOperatorTest();
    // VectorOverloadOperatorTest();
}

void PointConstructorTest() {
    // Default Constructor test
    // Point2 p1{};
    // cout << p1.toString();

    // Construct w/ values test
    // Point2 p1{1, 1};
    // cout << p1.toString();
}
void VectorConstructorTest() {
    // Default Constructor test;
    // Vector2 v1{};
    // cout << v1.toString();

    // Construct w/ values test
    // Vector2 v1{1, atan2(1,0)};
    // cout << v1.toString();
}
void PointOverloadOperatorTest() {
    // Point - Point = Vector
    // Point2 p1{};
    // Point2 p2{0,1};
    // Vector2 v1 = p2 - p1;
    // cout << p2.toString() << " - " << p1.toString() << " = " << v1.toString();

    // Point + Vector = Point
    // Point2 p1{};
    // Vector2 v1{sqrt(2), atan2(1,1)};
    // Point2 p2 = p1 + v1;
    // cout << p1.toString() << " + " << v1.toString() << " = " << p2.toString();

    // Point - Vector = Point
    // Point2 p1{};
    // Vector2 v1{sqrt(2), atan2(1,1)};
    // Point2 p2 = p1 - v1;
    // cout << p1.toString() << " - " << v1.toString() << " = " << p2.toString();
}
void VectorOverloadOperatorTest() {
    //Adding two vectors 
    // Vector2 v1{1, atan2(0,1)};
    // Vector2 v2{1, atan2(1,0)};
    // Vector2 v3 = v1 + v2;
    // cout << v1.toString() + " + " + v2.toString() + " = " + v3.toString();

    //Subtracting two vectors
    // Vector2 v1{1, atan2(0,1)};
    // Vector2 v2{1, atan2(1,0)};
    // Vector2 v3 = v1 - v2;
    // cout << v1.toString() + " - " + v2.toString() + " = " + v3.toString();

    //Scaling a vector
    // Vector2 v1{1, atan2(1,1)};
    // double scalar = 10;
    // Vector2 v2 = v1 * scalar;
    // cout << v1.toString() + " * " + std::to_string(scalar) + " = " + v2.toString();
}