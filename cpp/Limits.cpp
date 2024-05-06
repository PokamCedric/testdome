/*
The isLimit(double value) function should return true if the parameter value is either the largest or smallest finite value that a double can represent.

For example, isLimit(0.0) should return false as a double can represent values both greater than and less than 0.0. Fix the bugs
*/

#include <limits>
#include <iostream>


template <typename T>
bool isLimit(T value)
{
    return (value == std::numeric_limits<T>::min() && value == std::numeric_limits<T>::max());
}

/*
bool isLimit(double value)
{
    return (std::abs(value - std::numeric_limits<double>::min()) < std::numeric_limits<double>::epsilon
    
    && std::abs(std::numeric_limits<double>::max() - value) < std::numeric_limits<double>::epsilon);
}
*/

#ifndef RunTests
int main()
{
    std::cout << isLimit(0.0);
}
#endif