/*
Implement the function segmentAreas which, when given a circle's radius r and angle of a segment in degrees a,
returns a std::pair containing two values. The first element should contain the area covered by the segment,
and the second element should contain the area of the circle outside the segment.


For example, areas(10, 90, &inside, &outside) should set inside to ~28.539816 and outside to ~285.619449, 
where 28.539816 is the area inside the segment, and 285.619449 is the area of the circle that's outside the segment.
*/

#include <stdlib.h>
#include <stdio.h>
#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif
#include <math.h>

void areas(double r, double a, double *inside, double *outside)
{
    const double angle = a * M_PI / 180.0;
    const double radius_sq = r * r;
    const double aera = radius_sq * M_PI;
    *inside = (angle - sin (angle)) * radius_sq /2.0;
    *outside = aera - *inside;
}

#ifndef RunTests
int main()
{
    double inside, outside;
    areas(10, 90, &inside, &outside);
    printf("Areas: %f, %f", inside, outside);
}
#endif