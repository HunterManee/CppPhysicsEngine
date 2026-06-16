#include "vector"
#include "thread"

#include "engine/Transform.h"
#include "engine/Collider.hpp"
#include "engine/CircleCollider.h"
#include "engine/PolygonCollider.h"
#include "engine/Rigidbody.h"

#include "engine/Entity.h"
#include "engine/Collision.hpp"

#include "output/WebsocketOutput.hpp"

//Testing Testing

std::vector<Entity*> entities{};
const int MAX_ENTITIES = 100;
signed int id = 0;

void droppingEnitities() {
   if(entities.size() < MAX_ENTITIES) {

        //Transformation
        Vector randPosition = {
            Random::getRandomFloat(-400, 400),
            Random::getRandomFloat(400, 500)
        }; 
        Transform transform{randPosition};

        //Collider
        Collider* collider;
        switch(Random::getRandomInt(0,0)) {
            case 0:
                collider = new CircleCollider{};
                break;
            case 1:
                collider = new PolygonCollider{};
                break;
        }

        //Rigidbody
        float fallVelocity = Random::getRandomFloat(10, 200);
        Vector velocity((float)0, -fallVelocity);
        const double PI = 3.1415926535;
        double anglularVelocity = Random::getRandomDouble(-(PI / 36), (PI / 36));
        Rigidbody rigidbody{velocity, anglularVelocity};

        //Entity Creation
        Entity* entity = new Entity{id, transform, collider, &rigidbody};
        
        //Clean up
        delete collider;
        collider = nullptr;

        //Create Validation
        if(Collision::hasOverlappingCircle(*entity, entities, 5)) return;

        //Valid Entity Placement
        entities.push_back(entity);
        WebsocketOutput::createEntity(*entity);
        id++;

    }
}
void test() {
    
    if(entities.size() > 1) return;
    //Moving Circle
    Vector positionB((float)400, (float)300);
    Transform transformB{positionB};
    Collider* colliderB = new CircleCollider(100);
    Vector velocityB((float)-100, (float)-100);
    double angualarVelocityB = 0;
    Rigidbody rigidbodyB{velocityB, angualarVelocityB};
    Entity* entityB = new Entity{0, transformB, colliderB, &rigidbodyB};

    delete colliderB;
    colliderB = nullptr;
    entities.push_back(entityB);;
    WebsocketOutput::createEntity(*entityB);

    if(entities.size() > 2) return;
    //Static Circle
    Vector positionA((float)0, (float)0);
    Transform transformA{positionA};
    Collider* colliderA = new CircleCollider(100);
    Vector velocityA((float)0, (float)0);
    double angualarVelocityA = 0;
    Rigidbody rigidbodyA{velocityA, angualarVelocityA};
    Entity* entityA = new Entity{1, transformA, colliderA, &rigidbodyA};

    delete colliderA;
    colliderA = nullptr;
    entities.push_back(entityA);;
    WebsocketOutput::createEntity(*entityA);


    
}
void createEntities() {
 
    droppingEnitities();
}
void updateEntities(float dt) {
    

    //Start from the top of screen an work down
    std::sort(entities.begin(), entities.end(),
    [](Entity* a, Entity* b){
        float aMax = a->getTransform().getPosition().j + a->getBuildRadius();
        float bMax = b->getTransform().getPosition().j + b->getBuildRadius();
        return aMax > bMax;
    });

    Vector gravity((float)0, (float)-9.8);

    //update highest entities to lowest entities
    for(int index = 0; index < entities.size(); index++) {

        CollisionResults cr = Collision::findEarliestCollisions(index, entities, dt);

        Entity* entity = entities[index];

        Vector pos = entity->getTransform().getPosition();
        Vector vel = entity->getRigidbody()->getVelocity() + gravity * dt;
        entity->getRigidbody()->setVelocity(vel);
        Vector newPos = pos + vel * cr.collisionTime * dt;
        entity->getTransform().setPosition(newPos);

        std::cout << "CollisionTime: " << cr.collisionTime << std::endl;

        if(cr.collisionTime < 1.0) {
            Collision::testing(entity, cr);
            pos = entity->getTransform().getPosition();
            vel = entity->getRigidbody()->getVelocity();
            
            float remainingTime = 1.0 - cr.collisionTime;
            newPos = pos + vel * remainingTime * dt;
            entity->getTransform().setPosition(newPos);
            
        }


        WebsocketOutput::updateEntity(*entity);



    }

}
void deleteEntities() {

    for(auto it = entities.begin(); it != entities.end(); ){
        Entity* entity = *it;

        if(entity->getTransform().getPosition().j < -500) {
            WebsocketOutput::deleteEntity(*entity);
            delete entity;
            it = entities.erase(it);
        }
        else {
            ++it;
        }

    }

}


int main() {

    using Clock = std::chrono::steady_clock;
    constexpr auto frameTime = std::chrono::milliseconds(16);
    auto previous = Clock::now();
    
    while (true) {
        auto current = Clock::now();
        auto delta = current - previous;
        previous = current;

        float dt = std::chrono::duration<float>(delta).count();

        createEntities();
        updateEntities(dt);
        deleteEntities();

        auto frameElapsed = Clock::now() - current;

        if (frameElapsed < frameTime) {
            std::this_thread::sleep_for(frameTime - frameElapsed);
        }
    }
}