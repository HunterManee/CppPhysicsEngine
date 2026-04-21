#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"

struct Entity {
    Transform transform;
    Collider* collider;
    Rigidbody* rigidbody;
};
