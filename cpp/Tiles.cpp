/*
The tileEdges function takes a two-dimensional vector of bools that represents a tiled wall.

Complete the function so that the edges of the wall are tiled (set to true), and the center of the wall remains untiled (false).

For example, tileEdges(std::vector<std::vector<bool>>(4, std::vector<bool>(4))) should mark all edge tiles as true,
and leave other tiles as false, resulting in a 4x4 vector that looks like:
*/

#include <vector>
#include <iostream>

void tileEdges(std::vector<std::vector<bool>>& tiles)
{
    for (unsigned int x = 0; x < tiles.size(); x++)
    {
        tiles[x][0] = 1;
        tiles[x][tiles[x].size()-1] = 1;

        for (unsigned y = 0; y < tiles[x].size(); y++)
        {
            tiles[0][y] = 1;
            tiles[tiles.size() - 1][y] = 1;

        }
    }
    
}

#ifndef RunTests
int main()
{
    std::vector<std::vector<bool>> tiles(7, std::vector<bool>(5));
    tileEdges(tiles);
    for (unsigned x = 0; x < tiles.size(); x++)
    {
        for (unsigned y = 0; y < tiles[x].size(); y++)
        {
            std::cout << tiles[x][y];
        }
        std::cout << std::endl;
    }
}
#endif