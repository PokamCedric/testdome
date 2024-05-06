/*
An industrial building is being divided up and converted into apartments.A large apartment
takes up two stories of the building, and a small apartment takes up one story.

Write a function that, given the number of stories in the building, calculates the number
of different possible arrangements of apartments.

For example, if the building is three stories high it can accommodate three different possible
arrangements of apartments: small-small-small, small-large, and large-small.
*/

// Found Solution On: https://www.geeksforgeeks.org/count-possible-combinations-of-pairs-with-adjacent-elements-from-first-n-numbers/
#####---- Time complexity O(N)

#include <iostream>
#include <stdexcept>
#include <vector>

// vector to store the computed values
std::vector<int> dp;
// Function to count the number of ways
int ways(int n)
{
    // If there is a single number left
    // it will form singleton
    int& res = dp[n];

    // return the stored value
    // if the value is already computed
    if (res != -1)
        return res;

    // base case
    if (n == 1) {
        return res = 1;
    }

    // if there are just 2 numbers left,
    // they will form a pair
    if (n == 2) {
        return res = 2;
    }
    else {

        return res = ways(n - 1) + ways(n - 2);
    }
}

int numberOfArrangements(const int numberOfStories)
{
    dp = std::vector<int>(numberOfStories + 1, -1);
    return ways(numberOfStories);
}


#ifndef RunTests
int main()
{
    std::cout << numberOfArrangements(3);
}
#endif

#####---- Time complexity O(2*N)

#include <iostream>
#include <stdexcept>
#include <vector>

int numberOfArrangements(const int numberOfStories)
{
    // If there is a single number left
    // it will form singleton
    if (numberOfStories == 1) {
        return 1;
    }
    // if there are just 2 numbers left,
    // they will form a pair
    if (numberOfStories == 2) {
        return 2;
    }
    else {
        return numberOfArrangements(numberOfStories - 1) + numberOfArrangements(numberOfStories - 2);
    }
}


#ifndef RunTests
int main()
{
    std::cout << numberOfArrangements(3);
}
#endif

####------
#include <iostream>
#include <stdexcept>


int factorial(const int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

int factorialPartial(const int n, const int limit) {
    int factorial = 1;
    for (int i = limit + 1; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

int nCr(const int n, const int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int nCrWithPartialFactorial(const int n, const int k) {
    int lower = 1;
    int upper = 1;
    if (2 * k > n) {
        lower = n - k;
        upper = k;
    }
    else {
        lower = k;
        upper = n - k;
    }

    return factorialPartial(n, upper) / factorial(lower);
}

// A function to calculate combination using recurrence relation.
float CalcCombination(float n, float r)
{
    int i, res;
    if (r > 0)
        return (n / r) * CalcCombination(n - 1, r - 1);
    else
        return 1;
}

int numberOfArrangements(const int numberOfStories)
{
    constexpr int highCapacity = 2;
    int nberOfPossibleHigh = numberOfStories / highCapacity;
    int result = 1;
    int nberOfUsedHighs = 1;
    while (nberOfPossibleHigh--) {

        result += nCrWithPartialFactorial(numberOfStories - nberOfUsedHighs,
            numberOfStories - highCapacity * nberOfUsedHighs);
        nberOfUsedHighs++;
    }
    return result;
}


#ifndef RunTests
int main()
{
    std::cout << numberOfArrangements(7);
}
#endif


/* https://www.geeksforgeeks.org/count-possible-combinations-of-pairs-with-adjacent-elements-from-first-n-numbers/
Count possible combinations of pairs with adjacent elements from first N numbers

    Difficulty Level : Medium
    Last Updated : 16 Jun, 2022

Given a number N, the task is to count all possible combinations of pairs formed using adjacent elements.
Note: If an element exists already in a pair, it cannot be picked in the next pair. For example: for {1,2,3}: {1,2} and {2,3} will not be considered as a correct combination.
Examples: 
 

Input : N = 4
Output : 5
Explanation : If N = 4, the possible combinations are:
{1}, {2}, {3}, {4}
{1, 2}, {3, 4}
{1}, {2, 3}, {4}
{1}, {2}, {3, 4}
{1, 2}, {3}, {4}

Input : N = 5
Output : 8

 
Recommended: Please try your approach on {IDE} first, before moving on to the solution.

Approach : Break the problem into smaller subproblems. If there are N numbers, and there are two cases either a number is alone, or it is in a pair, if a number is alone, find the ways of pairing (n-1) numbers left, or if it is in a pair, find the ways of pairing (n-2) numbers left. If there are just 2 numbers left they can generate 2 combinations either alone or in a pair, and if a single number is left it will be in singleton, so there is just 1 combination.
Below is the implementation of the above approach:
 

#include <bits/stdc++.h>
using namespace std;
// Function to count the number of ways
int ways(int n)
{
    // If there is a single number left
    // it will form singleton
    if (n == 1) {
        return 1;
    }
    // if there are just 2 numbers left,
    // they will form a pair
    if (n == 2) {
        return 2;
    }
    else {
        return ways(n - 1) + ways(n - 2);
    }
}
 
// Driver Code
int main()
{
    int n = 5;
 
    cout << "Number of ways = " << ways(n);
 
    return 0;
}
Output: 

Number of ways = 8

 

Time Complexity: O(2^N)
Auxiliary Space: O(N)

Another Approach:

We can store the computed values in an array and reuse the computed value afterwords which would make the program efficient.

Implementation of the above approach:

// C++ implementation of the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
// vector to store the computed values
vector<int> dp;
 
// Function to count the number of ways
int ways(int n)
{
    // If there is a single number left
    // it will form singleton
      int& res = dp[n];
       
      // return the stored value
      // if the value is already computed
      if(res!=-1)
          return res;
   
      // base case
    if (n == 1) {
        return res=1;
    }
   
    // if there are just 2 numbers left,
    // they will form a pair
    if (n == 2) {
        return res=2;
    }
    else {
           
        return res = ways(n - 1) + ways(n - 2);
    }
}
 
// Driver Code
int main()
{
    int n = 5;
    dp = vector<int>(n + 1,-1);
    cout << "Number of ways = " << ways(n);
 
    return 0;
}
Output

Number of ways = 8

Time Complexity: O(n)

Auxiliary Space: O(n)

*/