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

std::vector<Entity*> entities{};
const int MAX_ENTITIES = 5;
signed int id = 0;

void createEntites() {
    while(entities.size() < MAX_ENTITIES) {

        //Transformation
        Vector randPosition = {
            Random::getRandomFloat(-400, 400),
            Random::getRandomFloat(50, 200)
        }; 
        Transform transform{randPosition};

        //Collider
        Collider* collider;
        switch(Random::getRandomInt(0, 1)) {
            case 0:
                collider = new PolygonCollider{};
                break;
            case 1:
                collider = new CircleCollider{};
                break;
        }

        //Rigidbody
        float fallVelocity = Random::getRandomFloat(1, 2);
        Vector velocity({0, -fallVelocity});
        const double PI = 3.1415926535;
        double anglularVelocity = Random::getRandomDouble(-(PI / 36), (PI / 36));
        Rigidbody rigidbody{velocity, anglularVelocity};

        //Entity Creation
        Entity* entity = new Entity{id, transform, collider, &rigidbody};
        
        //Clean up
        delete collider;
        collider = nullptr;

        //Create Validation
        if(Collision::hasOverlappingCircle(*entity, entities)) continue;

        //Valid Entity Placement
        entities.push_back(entity);
        WebsocketOutput::createEntity(*entity);
        id++;

    }
}

void updateEntities() {
    for(Entity* entity : entities) {
        entity->move();
        WebsocketOutput::updateEntity(*entity);
    }
}
void deleteEntities() {

    for(auto it = entities.begin(); it != entities.end(); ){
        Entity* entity = *it;

        if(entity->getTransform().getPosition().j < 0) {
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

    const std::chrono::milliseconds frameTime(16); //~60 FPS
    while(true){
        auto start = std::chrono::steady_clock::now();

        // --- Output JSON ---
        createEntites();
        updateEntities();
        deleteEntities();

        //Break Loop
        if(entities.size() == 0) break;

        // -- FRAME TIMEING ---
        auto elapsed = std::chrono::steady_clock::now() - start;
        if(elapsed < frameTime) {
            std::this_thread::sleep_for(frameTime - elapsed);
        }
    }
    
}