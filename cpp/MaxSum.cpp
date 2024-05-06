/*
Implement the findMaxSum method that, efficiently with respect to time used, returns the largest sum of any two elements in the given vector of positive numbers.

For example, the largest sum of the vector { 5, 9, 7, 11 } is the sum of the elements 9 and 11, which is 20.
*/

#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int findMaxSum( std::vector<int>& numbers)
{
    std::nth_element(numbers.begin(), numbers.begin()+2, numbers.end(), std::greater<int>{});
  
  return numbers.at(0) + numbers.at(1);
}

#ifndef RunTests
int main()
{
    std::vector<int> v { 5, 9, 7, 11 };
    std::cout << findMaxSum(v);
}
#endif