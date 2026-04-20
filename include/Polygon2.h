#include "Shape2.h"

struct Polygon2: public Shape2 {
    
    private: 
        int MIN_VERTICIES;
        int MAX_VERTICIES;

    public:
        Polygon2(const Point2& position);

};