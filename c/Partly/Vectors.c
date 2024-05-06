#include <math.h>
#include <float.h>
#include <stdio.h>

int find_shortest(int vectors[][3], int vector_count)
{
    int shortestIndex = 0;
    int prevSum = vectors[0][0] * vectors[0][0] + vectors[0][1] * vectors[0][1] + vectors[0][2] * vectors[0][2];
    int sum = 0;
    for (int x = 1; x < vector_count; x++) {
        sum = vectors[x][0] * vectors[x][0] + vectors[x][1] * vectors[x][1] + vectors[x][2] * vectors[x][1];
        if (sum <= prevSum) {
            shortestIndex = x;
        }
    }
    return shortestIndex;
}

#ifndef RunTests
int main()
{
    int vectors[3][3] = 
    {
        { 1, 1, 1 },
        { 2, 2, 2 },
        { 3, 3, 3 }
    };
    int shortest_index = find_shortest(vectors, 3);
    printf("Index: %d\n", shortest_index);
}
#endif