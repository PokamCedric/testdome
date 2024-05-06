/*
The tile_edges function takes a two-dimensional array of integers that represents a tiled wall.

Complete the function so that the edges of the wall are tiled (set to 1), and the center of the wall remains untiled (0). For example, the code below should mark all edge tiles as 1, and leave the rest of the tiles (tiles[5], tiles[6], tiles[9], and tiles[10]) as 0: 

int width = 4, height = 4;
int *tiles = calloc(width * height, sizeof(int)); // allocating memory and setting to 0
tile_edges(tiles, width, height);

The resulting 4x4 array should look like:
*/

#include <stdio.h>
#include <stdlib.h>

void tile_edges(int* tiles, int width, int height)
{
    for (unsigned x = 0; x < width; x++)
    {
        *(tiles + x) = 1;
        *(tiles + (height-1) * width + x) = 1;

        for (unsigned y = 1; y < height; y++)
        {
            *(tiles + y * width) = 1;
            *(tiles + y*width-1) = 1;
        }
    }
}


#ifndef RunTests
int main()
{
    int width = 4, height = 4;
    int* tiles = (int*)calloc(width * height, sizeof(int)); // allocating memory and setting to 0
    tile_edges(tiles, width, height);

    printf("%d %d %d %d \n%d %d %d %d \n%d %d %d %d \n%d %d %d %d ",
        tiles[0], tiles[1], tiles[2], tiles[3],
        tiles[4], tiles[5], tiles[6], tiles[7],
        tiles[8], tiles[9], tiles[10], tiles[11],
        tiles[12], tiles[13], tiles[14], tiles[15]);
}
#endif