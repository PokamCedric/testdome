/*
Implement a class Veterinarian that will be used as a part of a larger simulation of a veterinarian office.

The class Veterinarian needs to be efficient with respect to time used and contain the following methods:

    void accept(std::string petName) - puts the specified pet at the end of the line.
    std::string heal() - removes the pet's name from the queue and returns it. If no pets are in the queue, std::logic_error("Clinic is empty!") should be thrown.

For example, the following code snippet should write "Barkley", "Mittens":

Veterinarian veterinarian;
veterinarian.accept("Barkley");
veterinarian.accept("Mittens");
std::cout << veterinarian.heal() << std::endl;
std::cout << veterinarian.heal() << std::endl;
*/

#include <string>
#include <iostream>
#include <stdexcept>
#include <list>
#include <algorithm>

class Veterinarian
{
public:
    void accept(std::string petName)
    {
        patients.emplace_back(petName);
    }

    std::string heal()
    {
        std::string petName = patients.front();
        if(patients.size() > 0){
            patients.pop_front();
        }else{
            throw std::logic_error("Clinic is empty!");
        }

        return petName;
    }
private:
  std::list<std::string> patients;
};

#ifndef RunTests
int main()
{
    Veterinarian veterinarian;
    veterinarian.accept("Barkley");
    veterinarian.accept("Mittens");
    std::cout << veterinarian.heal() << std::endl;
    std::cout << veterinarian.heal() << std::endl;
}
#endif