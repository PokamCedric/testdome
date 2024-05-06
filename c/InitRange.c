/*
Implement the init_range function that initializes an array of given length which contains a sequence of integer numbers {0, 1, ..., length - 1}.

For example, init_range(6) should return a pointer to the following array: { 0, 1, 2, 3, 4, 5 }.
*/

#include <stdlib.h>
#include <stdio.h>

int *init_range(int length)
{
    int* ptr = (int*) malloc(length * sizeof(int));
    
    for(int i = 0; i < length; ++i) {
        *(ptr + i) = i;
    }
    return ptr;
}

#ifndef RunTests
int main ()
{
    int *range = init_range(6);
    for (int i = 0; i < 6; i++)
        printf("%d ", range[i]);
}
#endif