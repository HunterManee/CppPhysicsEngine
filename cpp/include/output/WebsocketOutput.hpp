#include "iostream"
#include "engine/Entity.h"

#include "external/nlohmann/json.hpp"
using json = nlohmann::json;

class WebsocketOutput {
    public:
        static void createEntity(const Entity& entity) {
            json j;
            j["type"] = "create";
            j["data"]["id"] = entity.getId();

            Transform transform = entity.getTransform();
            j["data"]["position"] = {
                {"x", (int)(transform.getPosition().i * 100) / 100.00},
                {"y", (int)(transform.getPosition().j * 100) / 100.00}
            };
            j["data"]["rotation"] = transform.getRotation();
            j["data"]["scale"] = {
                {"x", (int)(transform.getScale().i * 100) / 100.00},
                {"y", (int)(transform.getScale().j * 100) / 100.00}
            };

            Collider* collider = entity.getNewCollider();
            if(collider != nullptr) {
                if(auto circle = dynamic_cast<CircleCollider*>(collider)) {
                    j["data"]["shape"] = "circle";
                    j["data"]["radius"] = (int)(circle->getRadius() * 100) / 100.00;
                }else if(auto polygon = dynamic_cast<PolygonCollider*>(collider)) {
                    j["data"]["shape"] = "polygon";
                    j["data"]["vertices"] = json::array();
                    for(int i = 0; i < polygon->getTotalVerticies(); i++) {
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

            Rigidbody* rigidbody = entity.getNewRigidbody();
            if(rigidbody != NULL) {
                j["data"]["velocity"] = {
                    {"x", (int)(rigidbody->getVelocity().i * 100) / 100.00},
                    {"y", (int)(rigidbody->getVelocity().j * 100) / 100.00}
                };

                delete rigidbody;
                rigidbody = nullptr;
            }

            std::cout << j.dump() << std::endl;
        }

        static void updateEntity(const Entity& entity) {

            json j;
            j["type"] = "update";
            j["data"]["id"] = entity.getId();

            Transform transform = entity.getTransform();
            j["data"]["position"] = {
                {"x", (int)(transform.getPosition().i * 100) / 100.00},
                {"y", (int)(transform.getPosition().j * 100) / 100.00}
            };

            Rigidbody* rigidbody = entity.getNewRigidbody();
            if(rigidbody != NULL) {
                j["data"]["velocity"] = {
                    {"x", (int)(rigidbody->getVelocity().i * 100) / 100.00},
                    {"y", (int)(rigidbody->getVelocity().j * 100) / 100.00}
                };

                delete rigidbody;
                rigidbody = nullptr;
            }

            std::cout << j.dump() << std::endl;
        }

        static void deleteEntity(const Entity& entity) {
            json j;
            j["type"] = "delete";
            j["data"]["id"] = entity.getId();

            std::cout << j.dump() << std::endl;
        }

};