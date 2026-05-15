#include "Vector.hpp"

class Rigidbody{

    private:
        Vector Velocity{};

    public:
        Rigidbody();
        Rigidbody(Vector velocity);
        
        Rigidbody(const Rigidbody& toCopy);

        Vector getVelocity();
        void setVelocity(Vector velocity);


        std::string to_string() const;
        Rigidbody* clone() const;

};