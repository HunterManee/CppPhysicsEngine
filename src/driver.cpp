#include <iostream>
#include <cmath>

using namespace std;

#include "Point2.h"
#include "Vector2.h"
#include "PolygonCollider2.h"
#include "CircleCollider2.h"

#include "Rigidbody2.h"

#include "Entity.h"

int main() {

    /////////////////////////////
    // Point2 and Vector2 Test //
    /////////////////////////////

    // const double PI = 3.141592653589793;

    // Point2 p1(0, 0);
    // Vector2 v1(17, atan2(8,15));
    // Point2 p2 = p1 + v1;

    // cout << "X: " << p1.X << " Y: " << p1.Y << endl;
    // cout << "Mag: " << v1.Magnitude << " Theta: " << v1.Theta<< endl;
    // cout << "X: " << p2.X << " Y: " << p2.Y << endl;


    
    /////////////////////////////
    //      Entity Testing     //
    /////////////////////////////

    //Empty Entity & Add Components
    // Entity e{Transform{}};

    // vector<Point2> verticies;
    // e.AddComponent<PolygonCollider2>(verticies);
    // e.AddComponent<Rigidbody2>();


    //Entity with CircleCollider and Rigidbody
    // double radius = 10;
    // Entity e{
    //     Transform{},
    //     std::make_unique<CircleCollider2>(radius),
    //     std::make_unique<Rigidbody2>()
    // };

    //Entity with PolygonCollider and Rigidbody
    // vector<Point2> verticies;
    // Entity e{
    //     Transform{},
    //     std::make_unique<PolygonCollider2>(verticies),
    //     std::make_unique<Rigidbody2>()
    // };


}