/*
A large package can hold five items, while the small package can hold only one item. The available number of both large and small packages is limited. All items must be placed in packages and used packages have to be filled up completely.

Write a function that calculates the minimum number of packages needed to hold a given number of items. If it's not possible to meet the requirements, return -1.

For example, if we have 16 items, 2 large and 10 small packages, the function should return 8 (2 large packages + 6 small packages).
*/

#include <stdlib.h>
#include <stdio.h>

int minimal_number_of_packages(int items, int available_large_packages, int available_small_packages)
{
    const int nPossibleL = (items - items % 5) / 5;
        
    int restAfterL = -1;
    int usedLargest = -1;
    if(available_large_packages  > nPossibleL){
        usedLargest =  nPossibleL;
    }else{
        usedLargest = available_large_packages;
    } 
    restAfterL = items - usedLargest*5;

    if(restAfterL > available_small_packages){
        return -1;
    }
    return usedLargest + restAfterL;
}

#ifndef RunTests
int main()
{
    printf("%d", minimal_number_of_packages(16, 2, 10));
}
#endif