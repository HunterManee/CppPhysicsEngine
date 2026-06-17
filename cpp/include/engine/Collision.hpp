#pragma once
#include "vector"
#include "iostream"

#include "Entity.h"
#include "CircleCollider.h"
#include "PolygonCollider.h"

struct CollisionResults{
    float collisionTime;
    Entity* other = nullptr;
};

class Collision
{
    public:
        static bool hasOverlappingCircle(Entity& entity, std::vector<Entity*>& entities, float offset = 0) {
            for(Entity* e : entities) {
                if(entity.getId() == e->getId()) continue;
                Vector diff = entity.getTransform().getPosition() - e->getTransform().getPosition();
                float radius = entity.getBuildRadius() + e->getBuildRadius() + offset;
                if(diff.i * diff.i + diff.j * diff.j < radius * radius) return true;
            }
            return false;
        }

        static CollisionResults findEarliestCollisions(int entityIndex, std::vector<Entity*>& entities, float dt) {

            Entity* entity = entities[entityIndex];
            float T = 1;
            Entity* collided = nullptr;
            for(int i = 0; i < entities.size(); i++) {
                if(i == entityIndex) continue;

                //relating entity and other vertical coordinate
                Vector ePositionI = entity->getTransform().getPosition();
                Vector eVelocity = entity->getRigidbody()->getVelocity() * dt;
                Vector ePositionF = ePositionI + eVelocity;
                Vector lowestEntityPoint = 
                    (ePositionI.j - entity->getBuildRadius() < ePositionF.j - entity->getBuildRadius())? 
                    Vector{ePositionI.i, ePositionI.j - entity->getBuildRadius()} : 
                    Vector{ePositionF.i, ePositionF.j - entity->getBuildRadius()};
                Vector highestEnityPoint = 
                    (ePositionI.j + entity->getBuildRadius() > ePositionF.j + entity->getBuildRadius())? 
                    Vector{ePositionI.i, ePositionI.j + entity->getBuildRadius()} : 
                    Vector{ePositionF.i, ePositionF.j + entity->getBuildRadius()};
                

                Entity* other = entities[i];
                Vector oPosition = other->getTransform().getPosition();
                Vector highestOtherPoint = Vector{oPosition.i, oPosition.j + other->getBuildRadius()};
                Vector lowestOtherPoint = Vector{oPosition.i, oPosition.j - other->getBuildRadius()};
                
                float maxDistance = entity->getBuildRadius() + other->getBuildRadius();
                if(lowestOtherPoint.j - highestEnityPoint.j > maxDistance) continue;
                if(lowestEntityPoint.j - highestOtherPoint.j > maxDistance) break;

                Vector d = ePositionI - oPosition;
                Vector v = eVelocity;
                float r = entity->getBuildRadius() + other->getBuildRadius();

                float a = dot(v, v);
                if(a < 1e-6f)
                    continue;

                float b = 2.0f * dot(d, v);
                float c = dot(d, d) - r*r;

                if(c <= 0.0f)
                {
                    T = 0.0f;
                    collided = other;
                    break;
                }

                float discriminant = b*b - 4*a*c;
                if (discriminant < 0.0f)
                    continue;

                float sqrtD = sqrt(discriminant);
                float denom = 2.0f * a;

                if (fabs(denom) < 1e-6f)
                    continue;

                float t1 = (-b - sqrtD) / denom;
                float t2 = (-b + sqrtD) / denom;

                float collisionT = 1.0f + 1e-6f;

                if (t1 >= 0.0f && t1 <= 1.0f)
                    collisionT = t1;

                if (t2 >= 0.0f && t2 <= 1.0f)
                    collisionT = std::min(collisionT, t2);

                if (collisionT <= 1.0f && collisionT < T)
                {
                    T = collisionT;
                    collided = other;
                }
            }

            return CollisionResults{T, collided};

        }

        static void collisionResponse(Entity* entity, CollisionResults cr){
            Vector ePosition = entity->getTransform().getPosition();
            Vector oPosition = cr.other->getTransform().getPosition();
            Vector normal = (ePosition - oPosition).normalize();

            Vector eVelocity = entity->getRigidbody()->getVelocity();
            Vector oVelocity = cr.other->getRigidbody()->getVelocity();
            Vector relativeVelocity = eVelocity - oVelocity;

            float velAlongNormal = dot(relativeVelocity, normal);
            if(velAlongNormal > 0) return;

            float eMass = entity->getRigidbody()->getMass() * entity->getRigidbody()->getMass();
            float oMass = cr.other->getRigidbody()->getMass() * cr.other->getRigidbody()->getMass();

            float restitution = 1.0f; //1 = perfectly bouncy

            float impulseMagnitude =
                -(1 + restitution) * velAlongNormal /
                (1 / oMass + 1 / eMass);

            Vector impulse = normal * impulseMagnitude;

            oVelocity = oVelocity - impulse / oMass;
            eVelocity =  eVelocity  + impulse / eMass;

            entity->getRigidbody()->setVelocity(eVelocity);
            cr.other->getRigidbody()->setVelocity(oVelocity);
        }


    private:


};