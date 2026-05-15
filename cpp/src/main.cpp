#include <fstream>
#include <cmath>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;


#include "engine/Transform.h"
#include "engine/CircleCollider.h"
#include "engine/PolygonCollider.h"

#include "engine/Entity.h"

#include "engine/WebsocketOutput.hpp"


int maxEntities = 1;
int entitiesCreated = 0;

void createValidation() {
       while(WebsocketOutput::getEntitiesSize() < maxEntities) {
            Vector randPosition = {
                Random::getRandomFloat(-400, 400),
                Random::getRandomFloat(-300, 300)
            }; 
            Transform transform{randPosition};

            Collider* collider;
            switch(0) {
                case 0:
                    collider = new PolygonCollider{};
                    break;
                case 1:
                    collider = new CircleCollider{};
                    break;
            }

            Vector velocity{0, -9.80};
            Rigidbody rigidbody{velocity};

            Entity entity{entitiesCreated, transform, collider, &rigidbody};
            
            delete collider;
            collider = nullptr;

            WebsocketOutput::spawnEntity(entity);
            
            entitiesCreated++;
        }
}

void updateFalling() {
        for(int i = 0; i < WebsocketOutput::getEntitiesSize(); i++) {

        }
}



int main() {


    // --- MAIN LOOP ---
    const std::chrono::milliseconds frameTime(16); //~60 FPS
    while(true) {
        auto start = std::chrono::steady_clock::now();

        // --- OUTPUT JSON ---
        createValidation();

        // --- FRAME TIMING ---
        auto elapsed = std::chrono::steady_clock::now() - start;
        if (elapsed < frameTime) {
            std::this_thread::sleep_for(frameTime - elapsed);
        }

    }


}