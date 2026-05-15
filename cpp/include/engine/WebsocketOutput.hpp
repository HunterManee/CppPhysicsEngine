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

            Transform transform = entity.getTransform();
            j["data"]["position"] = {
                {"x", transform.getPosition().i},
                {"y", transform.getPosition().j}
            };
            j["data"]["rotation"] = transform.getRotation();
            j["data"]["scale"] = {
                {"x", transform.getScale().i},
                {"y", transform.getScale().j}
            };

            Collider* collider = entity.getCollider();
            if(collider != nullptr) {
                j["data"]["shape"] = collider->getShape();
                if(auto circle = dynamic_cast<CircleCollider*>(entity.getCollider())) {
                    j["data"]["radius"] = circle->getRadius();
                }else if(auto polygon = dynamic_cast<PolygonCollider*>(entity.getCollider())) {
                    j["data"]["vertices"] = json::array();
                    for(int i = 0; i < polygon->getSize(); i++) {
                        Vector vertex = polygon->getVertex(i);
                        j["data"]["vertices"].push_back({
                            {"x", (int)(vertex.i * 100) / 100.00},
                            {"y", (int)(vertex.j * 100) / 100.00}
                        });
                    }
                }

                delete collider;
                collider = nullptr;
            }

            Rigidbody* rigidbody = entity.getRigidbody();
            if(rigidbody != NULL) {
                j["data"]["velocity"] = {
                    {"x", rigidbody->getVelocity().i},
                    {"y", rigidbody->getVelocity().j}
                };

                delete rigidbody;
                rigidbody = nullptr;
            }

            std::cout << j.dump() << std::endl;
            entities.push_back(entity.clone());
        }
    
    
};



