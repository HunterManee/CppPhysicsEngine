#include <memory>

#include "Transform.h"
#include "Collider2.h"
#include "Rigidbody2.h"

struct Entity {
    Transform   transform;
    std::unique_ptr<Collider2> collider;
    std::unique_ptr<Rigidbody2> rigidbody;

    Entity(const Transform& t);
    Entity(const Transform& t, std::unique_ptr<Collider2> c, std::unique_ptr<Rigidbody2> r);
    
    
    template<typename T, typename... Args>
    T& AddComponent(Args&&... args);
};
