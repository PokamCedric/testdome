/*
Implement the function segmentAreas which, when given a circle's radius r and angle of a segment in degrees a,
returns a std::pair containing two values. The first element should contain the area covered by the segment,
and the second element should contain the area of the circle outside the segment.


For example, segmentAreas(10, 90) should return a std::pair<double, double> where first is set to ~28.539816 and second is ~285.619449,
where 28.539816 is the area inside the segment, and 285.619449 is the area of the circle that's outside the segment.
*/

#define _USE_MATH_DEFINES
#include <cmath>
#include <tuple>
#include <math.h>
#include <tuple>
#include <stdexcept>
#include <iostream>
#include <string>

std::pair<double, double> segmentAreas(double r, double a)
{
    const double angle = a * M_PI / 180.0;
    const double radius_sq = r * r;
    const double aera = radius_sq * M_PI;
    const double segMentArea = (angle - sin (angle)) * radius_sq /2.0;
    const double restAera = aera - segMentArea;

    return {segMentArea, restAera};
}

#ifndef RunTests
int main()
{
    std::pair<double,double> areas = segmentAreas(10, 90);
    std::cout << "Areas: " + std::to_string(areas.first) + ", " + std::to_string(areas.second);
}
#endif