#include<iostream>

#include "Point2.h"
#include "Vector2.h"

#include "Transform.h"

#include "JSonOutput.h"

//Structs
//--Point2--------------------------------
void PointConstructorTest() {
    // Default Constructor test
    // Point2 p1{};
    // std::cout << "Point1: " + p1.toString();

    // Construct w/ values test
    // Point2 p2{1, 1};
    // std::cout << "Point2: " + p2.toString();
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

//--Vector2-------------------------------
void VectorConstructorTest() {
    // Default Constructor test;
    // Vector2 v1{};
    // cout << v1.toString();

    // Construct w/ values test
    // Vector2 v1{1, atan2(1,0)};
    // cout << v1.toString();
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

//Classes
//--Transform-----------------------------
void TransformConstructorTest() {
    // Default Constructor test
    // Transform transform{};
    // cout << transform.toString();

    // Point Constructor test
    // Transform transform{Point2 {2,2}};
    // cout << transform.toString();

    // Point & Rotation Constructor test
    // Transform transform{Point2 {2,2}, 3.1415 / 4};
    // cout << transform.toString();
}
void TransformGetterAndSettersTest() {
    
    Transform t{};
    std::cout << t.toString();

    std::cout << "========= Setters ============\n";
    t.setPosition(Point2{2,2});
    t.setRotation(3.1415);
    t.setScale(Point2(-1,-1));   

    std::cout << "========= Getters ============\n";
    std::cout << "Position: " << t.getPosition().toString() << "\n";
    std::cout << "Rotation: " << std::to_string(t.getRotation()) << " Rads\n";
    std::cout << "Scale   : " << t.getScale().toString() << "\n";




}
void TransformBehaviorTest() {
    Transform t{};
    std::cout << "========= INITIAL ==========\n";
    std::cout << t.toString() << std::endl;

    const double magnitude = 2 * sqrt(2);
    const double theta = atan2(1,1);
    Vector2 velocity{magnitude, theta};
    t.move(velocity);

    std::cout << "========== FINAL ===========\n";
    std::cout << t.toString();



}

//--CircleCollider------------------------
void CircleColliderConstructorTest() {
    // Default Constructor (Random Radius)
    // CircleCollider c1{};
    // cout << c1.toString() << endl;

    //Constructor (double radius)
    // CircleCollider c1{5};
    // cout << c1.toString() << endl;
} 
//--PolygonCollider-----------------------
void PolygonColliderConstructorTest() {
    //Default Constructor (Random Vertices)
    // PolygonCollider p1{};
    // cout << p1.toString() << endl;

    //Constructor (Point2 vertices[], int size)
    // int size = 4;
    // Point2* vertices = new Point2[size]{
    //     {4, 4},
    //     {-4, 4},
    //     {-4, -4},
    //     {4, -4}
    // };
    // PolygonCollider p1{vertices, size};
    // cout << p1.toString() << endl;
}

//--Entity--------------------------------
void EntityColliderConstructorTest() {

}

//--JSon Output---------------------------
void JSonOutputTest() {

    JSonOutput jsonOutput;

    // Output Point Test
    // Point2 point;
    // jsonOutput.outputPoint(point);

    // Output Transform Test
    // Transform transform;
    // jsonOutput.outputTransform(transform);

    // Output CirlceCollider Test
    // Collider* collider = new CircleCollider();
    // Collider* collider = new PolygonCollider();
    // jsonOutput.outputCollider(collider);

    // Output Entity Test
    // Transform t{};
    // Collider* collider = new CircleCollider{};
    // Entity entity{t, collider};
    // delete collider;
    // jsonOutput.outputEntity(entity);
    
    // Output Entities Test
    // int totalEntities = Random::getRandomInt(5, 10);
    // Entity* entities = new Entity[totalEntities];
    // for(int i = 0; i < totalEntities; i++) {
    //     Point2 randPosition = {
    //         Random::getRandomDouble(-400, 400),
    //         Random::getRandomDouble(-300, 300)
    //     };
    //     Transform transform{randPosition};

    //     Collider* collider;
    //     switch (Random::getRandomInt(0,1))
    //     {
    //     case 0:
    //         collider = new CircleCollider();
    //         break;
    //     case 1:
    //         collider = new PolygonCollider();
    //         break;
    //     default:
    //         cout << "Invalid Shape" << endl;
    //         break;
    //     }

    //     entities[i] = Entity{transform, collider};
    // }

    // jsonOutput.outputEntities(entities, totalEntities);


}

