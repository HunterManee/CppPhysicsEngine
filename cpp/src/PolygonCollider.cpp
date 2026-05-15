#include "engine/PolygonCollider.h"
#include <iostream>

#include "engine/CircleCollider.h"
#include "engine/Vector.hpp"

//Constructor
PolygonCollider::PolygonCollider(){
    setRandVertices();
}
PolygonCollider::PolygonCollider(const std::vector<Vector> vertices)
{
    for(Vector vertex : vertices) {
        Vertices.push_back(vertex);
    }
}
//Destructor
PolygonCollider::~PolygonCollider() {}

//Copy Constructor
PolygonCollider::PolygonCollider(const PolygonCollider& toCopy) {
    for(Vector vertex : toCopy.Vertices) {
        Vertices.push_back(vertex);
    }
}

int PolygonCollider::getSize() {
    return Vertices.size();
}

Vector PolygonCollider::getVertex(int index) {
    return Vertices[index];
}

std::string PolygonCollider::getShape() const {
    return "polygon";
}

Collider* PolygonCollider::clone() const{
    return new PolygonCollider(*this);
}

std::string PolygonCollider::toString() const {
    std::string output;

    output += "--PolygonCollider--------------------\n";
    output += "--L--> Size: " + std::to_string(Vertices.size()) + "\n";
    output += "  L--> Vertices:\n";
    for(Vector vertex : Vertices) {
        output += "       L--> " + vertex.to_string() + "\n"; 
    }

    return output;
}


//Helper Methods
void PolygonCollider::setRandVertices() {

    //Choose a random number of vertices bewteen the min and max
    int totalVertices = Random::getRandomInt(Min_Vertices, Max_Vertices);

    //Create the range for the change in degree
    const double TAU = 6.283185307179586;
    double avgRadians = TAU / totalVertices;
    double offsetPercentage = .10;
    const double DELTA_RADIANS = avgRadians * .5 * (1 - offsetPercentage);

    //Create the max for the range for magnitude
    const double MAX_MAGNITUDE = Random::getRandomDouble(CircleCollider::MinRandRadius, CircleCollider::MaxRandRadius);

    Vector centroid{};
    for(int i = 0; i < totalVertices; i++) {

        double deltaRadians = Random::getRandomDouble(-DELTA_RADIANS, DELTA_RADIANS);
        double theta = i * avgRadians + deltaRadians;

        float magnitude = Random::getRandomDouble(CircleCollider::MinRandRadius, MAX_MAGNITUDE);

        Vector newVertex{magnitude, theta};

        Vertices.push_back(newVertex);

        centroid = centroid + newVertex;
    }

    //Determine the new center of the shape
    centroid = centroid / totalVertices;

    //Ajust Points based on the center of the shape
    for (int i = 0; i < totalVertices; i++) {
        Vertices[i] = Vertices[i] - centroid;
    }
    
}