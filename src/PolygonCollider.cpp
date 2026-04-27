#include "PolygonCollider.h"
#include <iostream>

//Constructor
PolygonCollider::PolygonCollider(const Point2 vertices[], int size):
Size{size} {
    Vertices = new Point2[Size];
    for(int i = 0; i < Size; i++) {
        Vertices[i] = vertices[i];
    }
}
//Destructor
PolygonCollider::~PolygonCollider() {
    delete[] Vertices;
    Vertices = nullptr;
    Size = 0;
}
//Copy Constructor
PolygonCollider::PolygonCollider(const PolygonCollider& toCopy):
Size{toCopy.Size} {
    Vertices = new Point2[Size];
    for(int i = 0; i < Size; i++) {
        Vertices[i] = toCopy.Vertices[i];
    }
}

void PolygonCollider::function() {
    std::cout << "From Polygon Collider" << std::endl;
}

Collider* PolygonCollider::clone() const{
    return new PolygonCollider(*this);
}

std::string PolygonCollider::toString() const {
    std::string output;

    output += "--PolygonCollider--------------------\n";
    output += "  L--> Vertices:\n";
    for(int i = 0; i < Size; i++) {
    output += "       L--> " + Vertices[i].toString() + "\n"; 
    }

    return output;
}