/*
Implement the inspect_bits function that checks if given number contains 2 or more consecutive ones in its binary representation. If it does, the function should return 1. Otherwise, it should return 0.

For example, inspect_bits(13) should return 1 as it contains 2 consecutive ones in its binary representation (1101).
*/

// Defining comparator function as per the requirement

#include <stdlib.h>
#include <stdio.h>

int inspect_bits(unsigned int number) {
    int cur, prev = 0;
    while (number > 0) {
        cur = number & (-number);
        if (prev * 2 == cur) {
            return 1;
        }
        number -= cur;
        prev = cur;
    }
    return 0;
}