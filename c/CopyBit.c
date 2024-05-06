/*

*/

#include <stdlib.h>
#include <stdio.h>

int copy_bit(int src, int dst, int pos)
{
    if (src & (1<< pos)) { // Checking a bit
        // Setting a bit
        dst |= 1UL << pos;
    }
    else {
        // Clearing a bit
        dst &= ~(1UL << pos);
    }
    return dst;
}

#ifndef RunTests
int main()
{
    printf("%d", copy_bit(7, 12, 3));
}
#endif