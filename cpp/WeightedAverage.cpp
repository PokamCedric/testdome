/*
The code works correctly for the given example, but users have complained that it doesn't work for some of their cases. Fix the bugs in the code.

The method must throw std::invalid_argument("Argument exception") for every illegal argument value or combination. The expected arguments are two arrays with the same length.

For example, mean called with numbers {3, 6} and weights {4, 2} should return the weighted mean (3 * 4 + 6 * 2) / (4 + 2) = 4.0.
*/

#include <stdexcept>
#include <iostream>
#include <vector>

double mean(const std::vector<int>& numbers, const std::vector<int>& weights)
{
    double total = 0.0;
    double totalWeights = 0.0;
    if(numbers.size() != weights.size()){
        throw std::invalid_argument("Argument exception");
    }
    for (size_t i = 0; i < numbers.size(); i++)
    {
        total += numbers[i] * weights[i];
        totalWeights += weights[i];
    }

    return total / totalWeights;
}

#ifndef RunTests
int main()
{
    std::vector<int> a, b;
    a.push_back(3);
    a.push_back(6);
    a.push_back(16);
    b.push_back(4);
    b.push_back(2);
    b.push_back(5);
    std::cout << mean(a, b);
}
#endif