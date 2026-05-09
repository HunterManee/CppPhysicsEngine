#include "engine/PolygonCollider.h"
#include <iostream>

#include "engine/CircleCollider.h"
#include "engine/Vector2.h"

//Constructor
PolygonCollider::PolygonCollider(){
    setRandVertices();
}
PolygonCollider::PolygonCollider(const std::vector<Point2> vertices)
{
    for(Point2 vertex : vertices) {
        Vertices.push_back(vertex);
    }
}
//Destructor
PolygonCollider::~PolygonCollider() {}

//Copy Constructor
PolygonCollider::PolygonCollider(const PolygonCollider& toCopy) {
    for(Point2 vertex : toCopy.Vertices) {
        Vertices.push_back(vertex);
    }
}

int PolygonCollider::getSize() {
    return Vertices.size();
}

Point2 PolygonCollider::getVertex(int index) {
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
    for(Point2 vertex : Vertices) {
        output += "       L--> " + vertex.toString() + "\n"; 
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

    Point2 centroid{};
    for(int i = 0; i < totalVertices; i++) {

        double deltaRadians = Random::getRandomDouble(-DELTA_RADIANS, DELTA_RADIANS);
        double radians = i * avgRadians + deltaRadians;

        double magnitude = Random::getRandomDouble(CircleCollider::MinRandRadius, MAX_MAGNITUDE);

        Vector2 vector{magnitude, radians};
        Point2 newVertex{vector.getDeltaX(), vector.getDeltaY()};

        Vertices.push_back(newVertex);

        centroid.X += newVertex.X;
        centroid.Y += newVertex.Y;
    }

    //Determine the new center of the shape
    centroid.X /= totalVertices;
    centroid.Y /= totalVertices;

    //Ajust Points based on the center of the shape
    for (int i = 0; i < totalVertices; i++) {
        Vertices[i].X -= centroid.X;
        Vertices[i].Y -= centroid.Y;
    }
}