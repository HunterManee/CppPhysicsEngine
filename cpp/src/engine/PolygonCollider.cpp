#include "engine/PolygonCollider.h"

PolygonCollider::PolygonCollider():
Collider{Polygon}{
    setRandVertices();
}
PolygonCollider::PolygonCollider(const PolygonCollider& toCopy):
Collider{toCopy.Shape}{
    for(Vector vertex : toCopy.Vertices) {
        Vertices.push_back(vertex);
    }
}

int PolygonCollider::getTotalVerticies(){
    return Vertices.size();
}
Vector PolygonCollider::getVertex(const int index) {
    return Vertices[index];
}

Collider* PolygonCollider::clone() const {
    return new PolygonCollider(*this);
}
std::string PolygonCollider::to_string() const {
    std::string output;

    output += "--PolygonCollider--------------------\n";
    output += "--L--> Size: " + std::to_string(Vertices.size()) + "\n";
    output += "  L--> Vertices:\n";
    for(Vector vertex : Vertices) {
        output += "       L--> " + vertex.to_string() + "\n"; 
    }

    return output;
}

void PolygonCollider::setRandVertices() {
    
    //Choose a random number of vertices between the min and max
    int totalVertices = Random::getRandomInt(Min_Vertices, Max_Vertices);

    //Vector{float magnitude, double theta}
    //Create the max for the range for magnitude
    const float MAX_MAGNITUDE = Random::getRandomFloat(Min_Build_Radius, Max_Build_Radius);

    //Create the range for the change in radians
    const double TAU = 6.283185307179586;
    double avgRadians = TAU / totalVertices;
    double offsetPrecentage = .10;
    const double DELTA_RADIANS = avgRadians * .5 * (1 - offsetPrecentage);

    std::vector<Vector> vertices;
    Vector centroid{};
    for(int i = 0; i < totalVertices; i++) {

        float magnitude = Random::getRandomFloat(Min_Build_Radius, MAX_MAGNITUDE);

        double deltaRadians = Random::getRandomDouble(-DELTA_RADIANS, DELTA_RADIANS);
        double theta = i * avgRadians + deltaRadians;

        Vector newVertex{magnitude, theta};
        vertices.push_back(newVertex);
        centroid = centroid + newVertex;
    }

    //Determine the new center of the shape
    centroid = centroid / totalVertices;

    for(Vector vertex : vertices) {
        Vertices.push_back(vertex - centroid);
    }
}
