/*
The code works correctly for the given example, but users have complained that it doesn't work for some of their cases. Fix the bugs in the code.

The function must return -1 when the inputs are NULL and return 0 otherwise. The first two arguments are arrays with length elements.

For example, mean called with numbers {3, 6} and weights {4, 2} should return the weighted mean (3 * 4 + 6 * 2) / (4 + 2) = 4.0.
*/

#include <stdio.h>

int mean(int* numbers, int* weights, int length, double* result)
{
    double total = 0.0;
    double total_weights = 0.0;
    if(numbers ==NULL || weights == NULL){
        return -1;
    }
    for (int i = 0; i < length; i++)
    {
        total += numbers[i] * weights[i];
        total_weights += weights[i];
    }

    *result = total / total_weights;
    return 0;
}

#ifndef RunTests
int main()
{
    int a[] = {3, 6};
    int b[] = {4, 2};

    double result;
    int status = mean(a, b, 2, &result);

    if (status == -1)
    {
        printf("Got an error status as return value\n");
    }
    else
    {
        printf("%lf\n", result); 
    }
}
#endif