#pragma once

#include "Transform.h"
#include "Collider.hpp"
#include "Rigidbody.h"

class Entity{
    
    private:
        const signed int ID;
        Transform transform;
        Collider* collider;
        Rigidbody* rigidbody;
    
    public:
        Entity(signed int id = 0);
        Entity(signed int id, const Collider* c);
        Entity(signed int id, const Collider* c, const Rigidbody* r);

        Entity(signed int id, const Transform& t);
        Entity(signed int id, const Transform& t, const Collider* c);
        Entity(signed int id, const Transform& t, const Collider* c, const Rigidbody* r);

        Entity(const Entity& toCopy);
        ~Entity();

        signed int getId() const;
        SHAPE getShape() const;
        float getBuildRadius() const;
        Transform& getTransform() ;
        Collider* getNewCollider() const;
        Rigidbody* getRigidbody() const;

        void move(float dt);
        void move(Vector acceleration, float dt);
        void move(double angularAcceleration, float dt);

        Entity* clone() const;
        std::string to_string() const;


};