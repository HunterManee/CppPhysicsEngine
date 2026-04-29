#pragma once

#include "Collider.h"
#include "Point2.h"

class PolygonCollider : public Collider{
    private:
        Point2* Vertices{nullptr};
        int Size{0};

        const int Min_Vertices{3};
        const int Max_Vertices{8};
        
    public:
        //Constructor
        PolygonCollider();
        PolygonCollider(const Point2 vertices[], int size);
        //Destructor
        ~PolygonCollider() override;
        //Copy Constructor
        PolygonCollider(const PolygonCollider& toCopy);

        void function() override;
        void addElement(const Point2& entry);

        Collider* clone() const override;
        std::string toString() const override;


    private: //Helper Methods
        void setRandVertices();

    };