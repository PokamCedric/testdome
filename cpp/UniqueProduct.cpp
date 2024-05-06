/*
Write a method that, efficiently with respect to time used, finds the first product in a vector that
occurs only once in that vector. If there are no unique products in the vector, an empty string should be returned.

For example, for vector products containing { "Apple", "Computer", "Apple", "Bag" }, firstUniqueProduct(products) should return "Computer".
*/

#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string firstUniqueProduct(const std::vector<std::string>& products)
{
    std::unordered_map<std::string, int> count;
    for (std::string item : products) {
        ++count[item];
    }

    std::string uniqueProduct = "";

    for (std::string item : products) {
        if (count[item] == 1) {
            uniqueProduct = item;
            break;
        }
    }

    return uniqueProduct;
}

#ifndef RunTests
int main()
{
    std::vector<std::string> products = { "Apple", "Computer", "Apple", "Bag" };
    std::cout << firstUniqueProduct(products);
}
#endif