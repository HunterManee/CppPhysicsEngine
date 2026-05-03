#include "JSonOutput.h"

#include <iostream>
#include <typeinfo>

void JSonOutput::outputPoint(const Point2& point) {
    json j = serializePoint(point);
    outputJSon(j);
}

void JSonOutput::outputTransform(const Transform& transform) {
    json j = serializeTransform(transform);
    outputJSon(j);
}

void JSonOutput::outputCollider(Collider* collider) {
    json j = serializeCollider(collider);
    outputJSon(j);
}

void JSonOutput::outputEntity(const Entity& entity) {
    json j = serializeEntity(entity);
    outputJSon(j);
}

void JSonOutput::outputEntities(const Entity entities[], int totalEntities){
    json j = serializeEntities(entities, totalEntities);
    outputJSon(j);
}

// Private Helper Methods

void JSonOutput::outputJSon(const json j) {
    std::ofstream file(FileName);

    if(!file) {
        std::cerr << "Failed to open file\n";
    }
    
    file << j.dump(4);
}



json JSonOutput::serializePoint(const Point2& point) {
    json j;
    j = {
        {"x", point.X},
        {"y", point.Y}
    };
    return j;
}

json JSonOutput::serializeTransform(const Transform& transform) {
    json j;

    j["position"]   = serializePoint(transform.getPosition());
    j["rotation"]   = transform.getRotation();
    j["scale"]      = serializePoint(transform.getScale());

    return j;
}

json JSonOutput::serializeCollider(Collider* collider) {    
    json j;
    if (collider == nullptr) return j;
    
    if(auto circle = dynamic_cast<CircleCollider*>(collider)) {
        j["type"] = "circle";
        j["radius"] = circle->getRadius();

    }else if(auto polygon = dynamic_cast<PolygonCollider*>(collider)) {
        j["type"] = "polygon";
        for(int i = 0; i < polygon->getSize(); i++){
            json point = serializePoint(polygon->getVertex(i));
            j["vertices"].push_back(point);
        }
    }
    
    return j;

}

json JSonOutput::serializeEntity(Entity entity) {
    json j;

    Transform t = entity.getTransform();
    Collider* c = entity.getCollider();

    j["transform"] = serializeTransform(t);
    j["collider"] = serializeCollider(c);

    delete c;
    return j;
}

json JSonOutput::serializeEntities(const Entity entities[], int totalEntities) {
    json j = json::array();

    for(int i = 0; i < totalEntities; i++) {
        j.push_back(serializeEntity(entities[i]));
    }

    return j;
}

