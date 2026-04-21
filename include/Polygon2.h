#include "Shape2.h"
#include <vector>

struct Polygon2: public Shape2 {
    
    private: //Variables
        std::vector<Point2> Verticies;

    public:
        Polygon2(const Point2& position, const std::vector<Point2>& verticies);
        Polygon2(const Point2& position, double rotation, const std::vector<Point2>& verticies);

    
};