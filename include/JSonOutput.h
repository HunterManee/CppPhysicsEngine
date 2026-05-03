#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <fstream>

#include "Point2.h"

#include "Transform.h"

#include "Collider.h"
#include "CircleCollider.h"
#include "PolygonCollider.h"

#include "Entity.h"

class JSonOutput {

    std::string FileName{"data.json"};

    public:
    // Constructors
    JSonOutput(){};
    JSonOutput(std::string& fileName);

    //Behaviors
    void outputPoint(const Point2& point);
    void outputTransform(const Transform& transform);
    void outputCollider(Collider* collider);
    void outputEntity(const Entity& entity);
    void outputEntities(const Entity entities[], int totalEntities);

    private: //Private Helpers
    void outputJSon(const json j);
    json serializePoint(const Point2& point);
    json serializeTransform(const Transform& Transform);
    json serializeCollider(Collider* collider);
    json serializeEntity(Entity entity);
    json serializeEntities(const Entity entities[], int totalEntities);


};