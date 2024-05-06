/*
Implement the function find_roots to find the roots of the quadratic equation: ax2 + bx + c = 0.
If the equation has only one solution, the function should return that solution as both roots. The equation will always have at least one solution.

The roots of the quadratic equation can be found with the following formula: A quadratic equation.

For example, the roots of the equation 2x2 + 10x + 8 = 0 are -1 and -4.
*/

#include <stdlib.h>
#include <stdio.h>

void find_roots(double a, double b, double c, double *root1, double *root2)
{
  double sqroot = sqrt((b * b) - 4 * a * c);
  
  *root1 = (-b + sqroot)/(2.0*a);
  *root2 = (-b - sqroot)/(2.0*a);
}
