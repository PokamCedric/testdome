/*
Implement the function findRoots to find the roots of the quadratic equation: ax2 + bx + c = 0.
If the equation has only one solution, the function should return that solution as both elements of the pair.
The equation will always have at least one solution.

The roots of the quadratic equation can be found with the following formula: A quadratic equation.

For example, the roots of the equation 2x2 + 10x + 8 = 0 are -1 and -4.
*/

#include <iostream>
#include <string>
#include <cmath>

std::pair<double, double> findRoots(double a, double b, double c)
{
  const double sqroot = std::sqrt((b * b) - 4 * a * c);
  
  return {(-b + sqroot)/(2.0*a), (-b - sqroot)/(2.0*a)};
}
