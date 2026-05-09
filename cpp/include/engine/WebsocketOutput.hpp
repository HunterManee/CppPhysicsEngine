#include <vector>
#include "Entity.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "Collider.h"
#include "CircleCollider.h"
#include "PolygonCollider.h"


#include <iostream>
class WebsocketOutput{
    inline static std::vector<Entity*> entities{};

    public:

        static int getEntitiesSize() {
            return entities.size();
        }
        static void spawnEntity(const Entity& entity) {
        
            json j;

            j["type"] = "spawn";
            j["data"]["id"] = entity.getID();

            Collider* collider = entity.getCollider();
            j["data"]["shape"] = collider->getShape();
            if(auto circle = dynamic_cast<CircleCollider*>(entity.getCollider())) {
                j["data"]["radius"] = circle->getRadius();
            }else if(auto polygon = dynamic_cast<PolygonCollider*>(entity.getCollider())) {
                j["data"]["vertices"] = json::array();
                for(int i = 0; i < polygon->getSize(); i++) {
                    Point2 vertex = polygon->getVertex(i);
                    j["data"]["vertices"].push_back({
                        {"x", (int)(vertex.X * 100) / 100.00},
                        {"y", (int)(vertex.Y * 100) / 100.00}
                    });
                }
            }
            
            delete collider;
            collider = nullptr;

            Transform t = entity.getTransform();
            j["data"]["position"] = json::array();
            j["data"]["position"].push_back(t.getPosition().X);
            j["data"]["position"].push_back(t.getPosition().Y);
            j["data"]["rotation"] = t.getRotation();
            j["data"]["scale"] = json::array();
            j["data"]["scale"].push_back(t.getScale().X);
            j["data"]["scale"].push_back(t.getScale().Y);


            std::cout << j.dump() << std::endl;
            entities.push_back(entity.clone());
        }
    
    
};



