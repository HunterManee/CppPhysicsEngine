#pragma once
#include <vector>

#include "Collider.h"
#include "Vector.hpp"


class PolygonCollider : public Collider{
    private:
        std::vector<Vector> Vertices;

        const int Min_Vertices{3};
        const int Max_Vertices{8};
        
    public:
        //Constructor
        PolygonCollider();
        PolygonCollider(const std::vector<Vector> vertices);
        //Destructor
        ~PolygonCollider() override;
        //Copy Constructor
        PolygonCollider(const PolygonCollider& toCopy);

        int getSize();
        Vector getVertex(int index);

        std::string getShape() const override;
        Collider* clone() const override;
        std::string toString() const override;

    private: //Helper Methods
        void setRandVertices();

    };