/*
A large package can hold five items, while the small package can hold only one item. The available number of both large and small packages is limited. All items must be placed in packages and used packages have to be filled up completely.

Write a function that calculates the minimum number of packages needed to hold a given number of items. If it's not possible to meet the requirements, return -1.

For example, if we have 16 items, 2 large and 10 small packages, the function should return 8 (2 large packages + 6 small packages).
*/

#include <stdexcept>
#include <iostream>

####----- Perfect  4/4
int minimalNumberOfPackages(int items, int availableLargePackages, int availableSmallPackages)
{
    const int nPossibleL = (items - items % 5) / 5;
        
    int restAfterL = -1;
    int usedLargest = -1;
    if(availableLargePackages  > nPossibleL){
        usedLargest =  nPossibleL;
    }else{
        usedLargest = availableLargePackages;
    } 
    restAfterL = items - usedLargest*5;

    if(restAfterL > availableSmallPackages){
        return -1;
    }
    return usedLargest + restAfterL;
}


####-----not good  1/4
int minimalNumberOfPackages(int items, int availableLargePackages, int availableSmallPackages)
{
    int usedLargest = 0;
    // check largest
    while((usedLargest < availableLargePackages) && (((usedLargest + 1) * 5) < items)) {
        usedLargest++;
    }
    const int restItems = items - usedLargest * 5;
    if(restItems > availableSmallPackages){
        return -1;
    }
    return usedLargest + restItems;
    //throw std::logic_error("Waiting to be implemented");
}

#ifndef RunTests
int main()
{
    std::cout << minimalNumberOfPackages(15, 2, 3);
}
#endif