/*
Implement the findAllHobbyists function that takes a hobby, and an object consisting of peoples names mapped to their respective hobbies. The function should return a std::vector<std::string> containing the names of the people (in any order) that enjoy the hobby.

For example, the following code should display the name 'Chad'.

HobbiesMap hobbies 
{
   {"Steve", {"Fashion", "Piano", "Reading"}},
   {"Patty", {"Drama", "Magic", "Pets"}},
   {"Chad", {"Puzzles", "Pets", "Yoga"}}
};
        
std::vector<std::string> hobbyists = findAllHobbyists("Yoga", hobbies);
for (std::string hobbyist: hobbyists)
{
    std::cout << hobbyist << std::endl;
}

*/

#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <string>
#include <algorithm>

typedef std::map<std::string, std::vector<std::string>> HobbiesMap;

std::vector<std::string> findAllHobbyists(const std::string& hobby, const HobbiesMap& hobbies)
{
    std::vector<std::string> names;
    for (const auto& n : hobbies) {
        bool found = std::find(n.second.begin(), n.second.end(), hobby) != n.second.end();
        if(found){
            names.push_back(n.first);
        }
    }
    
    return names;
}
