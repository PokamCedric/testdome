/* ----Crop Ratio
The CropRatio object can be used to calculate what proportion of a farm's harvest is a specific crop. The object's proportion method should return 0 for crops that were not added.

For example:

CropRatio cropRatio;
cropRatio.add("Wheat", 4);
cropRatio.add("Wheat", 5);
cropRatio.add("Rice", 1);

Running cropRatio.proportion("Wheat") should return 0.9.

Fix the bugs.
*/

#include <iostream>
#include <string>
#include <map>

typedef std::map<std::string, int> MappedType;

class CropRatio
{
public:
    void add(std::string name, int cropWeight)
    {
        MappedType::iterator search = crops.find(name);
        if(search == crops.end()){
            std::cout << "Key-value pair not present in map" << "\n" ;
            crops.insert({name, cropWeight});
        }
        else{
            crops[name] = search->second + cropWeight;
            std::cout << "Key-value pair present : " 
              << search->first << " -> " << search->second << "\n";
        }
        totalWeight += cropWeight;
        
        std::cout << "total " << totalWeight << std::endl;
    }

    double proportion(std::string name)
    {
        MappedType::iterator search = crops.find(name);
        (search == crops.end()){
            return 0;
        }
        else{
            return (double)crops.at(name) / (double)totalWeight;
        }
    }

private:
    int totalWeight = 0;
    MappedType crops;
};

#ifndef RunTests
int main()
{
    CropRatio cropRatio;
    cropRatio.add("Wheat", 4);
    cropRatio.add("Wheat", 5);
    cropRatio.add("Rice", 1);

    std::cout << "Proportion of wheat: " << cropRatio.proportion("Wheat") << '\n';
    std::cout << "Proportion of wheat: " << cropRatio.proportion("Brot") << '\n';
}
#endif
