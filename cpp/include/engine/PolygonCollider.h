#pragma once

#include "Collider.h"
#include "Point2.h"
#include <vector>

class PolygonCollider : public Collider{
    private:
        std::vector<Point2> Vertices;

        const int Min_Vertices{3};
        const int Max_Vertices{8};
        
    public:
        //Constructor
        PolygonCollider();
        PolygonCollider(const std::vector<Point2> vertices);
        //Destructor
        ~PolygonCollider() override;
        //Copy Constructor
        PolygonCollider(const PolygonCollider& toCopy);

        int getSize();
        Point2 getVertex(int index);

        std::string getShape() const override;
        Collider* clone() const override;
        std::string toString() const override;

    private: //Helper Methods
        void setRandVertices();

    };