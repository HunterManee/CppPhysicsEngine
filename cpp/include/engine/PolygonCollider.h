#pragma once
#include "vector"
#include "Vector.hpp"
#include "Collider.hpp"

class PolygonCollider : public Collider {
    private:
        const int Min_Vertices{3};
        const int Max_Vertices{8};

        std::vector<Vector> Vertices;
    
    public:
        PolygonCollider();
        PolygonCollider(const PolygonCollider& toCopy);

        int getTotalVerticies();
        Vector getVertex(const int index);

        Collider* clone() const override;
        std::string to_string() const override;
    
    private:
        void setRandVertices();

};
