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

#include "engine/JSonOutput.h"

#include "engine/WebsocketOutput.hpp"


int maxEntities = 10;
int entitiesCreated = 0;

void createValidation() {
       while(WebsocketOutput::getEntitiesSize() < maxEntities) {
            Point2 randPosition = {
                Random::getRandomDouble(-400, 400),
                Random::getRandomDouble(-300, 300)
            }; 
            Transform t{randPosition};

            Collider* collider = new PolygonCollider();
            Entity entity{entitiesCreated, t, collider};
            
            delete collider;
            collider = nullptr;

            WebsocketOutput::spawnEntity(entity);
            
            entitiesCreated++;
        }
}



int main() {


    // --- MAIN LOOP ---
    const std::chrono::milliseconds frameTime(16); //~60 FPS
    while(true) {
        auto start = std::chrono::steady_clock::now();

        // --- OUTPUT JSON ---
        createValidation();
        // IMPORTANT: ensure newline + flush inside outputEntities !

        // --- FRAME TIMING ---
        auto elapsed = std::chrono::steady_clock::now() - start;
        if (elapsed < frameTime) {
            std::this_thread::sleep_for(frameTime - elapsed);
        }

    }


}

void MainHold() {
//Server Test
    JSonOutput jsonOutput;

    int totalEntities = Random::getRandomInt(5,10);
    Entity* entities = new Entity[totalEntities];
    for(int i = 0; i < totalEntities; i++) {
        Point2 randPosition = {
            Random::getRandomDouble(-400, 400),
            Random::getRandomDouble(-300, 300)
        };
        Transform transform{randPosition};

        Collider* collider;
        switch (Random::getRandomInt(0,1))
        {
        case 0:
            collider = new CircleCollider();
            break;
        case 1:
            collider = new PolygonCollider();
            break;
        }

        entities[i] = Entity{i, transform, collider};
    }


    // --- MAIN LOOP ---
    const std::chrono::milliseconds frameTime(16); //~60 FPS
    while(true) {
        auto start = std::chrono::steady_clock::now();

        // --- OUTPUT JSON ---
        jsonOutput.outputEntities(entities, totalEntities);

        // IMPORTANT: ensure newline + flush inside outputEntities !

        // --- FRAME TIMING ---
        auto elapsed = std::chrono::steady_clock::now() - start;
        if (elapsed < frameTime) {
            std::this_thread::sleep_for(frameTime - elapsed);
        }

    }
}