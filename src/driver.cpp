#include <iostream>
#include <cmath>

using namespace std;

#include "Point2.h"
#include "Vector2.h"
#include "Shape2.h"

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
    //       Shape2 Test       //
    /////////////////////////////
    
    Shape2 shape2{};

    cout << "X coor: " << shape2.Position.X << endl;
    cout << "Y coor: " << shape2.Position.Y << endl;


}