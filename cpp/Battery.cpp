/* ----Battery
A Battery's charge is represented as a float and is empty (0.0) by default.

Implement the charge function so that the battery's charge is increased by the supplied value.

For example, if the Battery's current charge is 0.0, then charge(battery, 1.0f) should increase the battery's charge field by 1.0f.
*/

#include <algorithm>
#include <iostream>

struct Battery
{
    float charge = 0.0f;
};

void charge(Battery* battery, float charge)
{
  if(battery->charge <= 100.0f){
      battery->charge += charge;
  
  }
}

#ifndef RunTests
int main()
{
    Battery battery;
    charge(&battery, 1.0f);
    std::cout << battery.charge << std::endl;
}
#endif