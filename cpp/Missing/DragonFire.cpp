#include <stdexcept>
#include <functional>

class ReptileEgg;

class Reptile
{
public:
    virtual ~Reptile() {};
    virtual ReptileEgg* lay() = 0;
};

class ReptileEgg
{
public:
    ReptileEgg(std::function<Reptile* ()> createReptile)
    {
        createReptile();
    }

    Reptile* hatch()
    {
        return new FireDragon();
    }
};

class FireDragon : public Reptile
{
public:
    FireDragon()
    {
    }

    ReptileEgg* lay()
    {
        return new ReptileEgg([]() { return new FireDragon(); });
    }

};

#ifndef RunTests
int main()
{
    Reptile* fireDragon = new FireDragon();

    ReptileEgg* egg = fireDragon->lay();
    Reptile* childDragon = egg->hatch();
}
#endif