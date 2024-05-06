/*
Write a method that finds, efficiently with respect to time used, all numbers that occur exactly once in the input vector.

For example, for vector numbers containing { 1, 2, 1, 3 }, findUniqueNumbers(numbers) should return a vector containing { 2, 3 }.
*/

/*
 - Utiliser le unordered_map pour compter le nombre d'apparence de chaqu'élement.
 - Utiliser copy_if pour ne copier que les singletons
*/

#include <vector>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> findUniqueNumbers(const std::vector<int>& numbers)
{
    std::unordered_map<int, int> count;
    for (int item : numbers) {
        ++count[item];
    }

    std::vector<int> uniqueNumbers;
    auto predicate = [&](auto item) {return count[item] == 1; };
    std::copy_if(numbers.begin(), numbers.end(), back_inserter(uniqueNumbers), predicate);

    return uniqueNumbers;
}

#ifndef RunTests
int main()
{
    std::vector<int> numbers = { 1, 2, 1, 3 };
    std::vector<int> result = findUniqueNumbers(numbers);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << '\n';
}
#endif