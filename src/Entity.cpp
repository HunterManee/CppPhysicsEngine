#include "Entity.h"

Entity::Entity(const Transform& t):
transform{t} {}

Entity::Entity(const Transform& t, std::unique_ptr<Collider2> c, std::unique_ptr<Rigidbody2> r):
transform{t}, 
collider(std::move(c)),
rigidbody(std::move(r)) {}


template<typename T, typename... Args>
/**
 * @brief Create a component (Collider/Rigidbody), store it inside Entity
 * @return Reference to the component
 * 
 * Args&&... args => I accept ANY constructor argument for the component.
 * 
 */
T& AddComponent(Args&&... args) { 
    //if T is a Collider type, compile this block. Otherwise, ignore it completely
    if constexpr (std::is_base_of_v<Collider2, T) {
        //Create a new component on the heap, and store it inside the entity's collider pointer
        collider = std::make_unique<T>(std::forward<Args>(args)...);
        return *static_cast<T*>(collider.get());
    }
    //if T is a Rigidbody type, compile this block. Otherwise, ignore it completely
    else if constexpr (std:: is_base_of_v<Rigidbody2, T>) {
        //Create a new component on the heap, and store it inside the entity's rigidbody pointer
        rigidbody = std::make_unique<T>(std::forward<Args>(args)...);
        return *static_cast<T*>(rigidbody.get());
    }
}