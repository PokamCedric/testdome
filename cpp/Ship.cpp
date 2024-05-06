/*
A ship has containerCount containers indexed as 0, 1, ..., containerCount - 1. Each container must be filled in the constructor
of the Ship using the fillContainer function, which accepts the container's index and returns the container's cargo.

The code below works, but the server has enough memory only for a ship with few containers. Change the code so that the server
has enough memory even for a ship with many containers.
*/


#include <iostream>
#include <unordered_map>
#include <vector>
#include <functional>

class Ship
{
public:
    Ship(const int containerCount, std::function<int(int)> fillContainer)
    {
        containers = new int[containerCount];
        
        for (int i = 0; i < containerCount; i++)
        {
            this->containers[i] = fillContainer(i);
        }
    }

    int peekContainer(int containerIndex)
    {
        return this->containers[containerIndex];
    }

private:
    int* containers;
};

#ifndef RunTests
int main()
{
    Ship ship(10, [](int containerIndex) { return containerIndex; });

    for (int i = 0; i < 10; i++) {
        std::cout << "Container: " << i << ", cargo: " << ship.peekContainer(i) << "\n";
    }
}
#endif
