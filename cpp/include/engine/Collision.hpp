#pragma once
#include "vector"

#include "Entity.h"
#include "CircleCollider.h"
#include "PolygonCollider.h"

class Collision
{
    public:
        static bool hasOverlappingCircle(Entity& entity, std::vector<Entity*>& entities, float offset = 0) {
            float entityRadius = getOverlapRadius(entity);
            for(Entity* e : entities) {
                if(entity.getId() == e->getId()) continue;
                Vector diff = entity.getTransform().getPosition() - e->getTransform().getPosition();
                float radius = entityRadius + getOverlapRadius(*e) + offset;
                if(diff.i * diff.i + diff.j * diff.j < radius * radius) return true;
            }
            return false;
        }

    private:
        static float getOverlapRadius(Entity& entity) {
            Collider* collider = entity.getNewCollider();
            float radius = 0;
            if(auto circle = dynamic_cast<CircleCollider*>(collider)) {
                radius = circle->getRadius();
            }else if (auto polygon = dynamic_cast<PolygonCollider*>(collider)) {
                for(int i = 0; i < polygon->getTotalVerticies(); i++) {
                    float magnitude = polygon->getVertex(i).magnitude();
                    if(magnitude < radius) continue;
                    radius = magnitude;
                }
            }

            delete collider;
            collider = nullptr;

            return radius;
        }

};