/*
A character in a platformer game is standing on a single row of floor tiles numbered 0 to N, at position X.

When the character moves, the tile at the previous position disappears. The character can only move left and right, and always jumps over one tile, and any holes. The character will not move if there are no tiles left to move to (you do not need to implement this in the code).

Implement a class that models this behavior and can report the character's position efficiently with respect to time used.

For example, Platformer(6, 3) creates a row of 6 tiles (numbered 0 to 5) and a character positioned on tile 3 {0 1 2 [3] 4 5}. A call to jumpLeft() moves the character two tiles to the left and the tile at position 3 disappears {0 [1] 2 4 5}. A subsequent call to jumpRight() moves the character two tiles to the right and the tile at position 1 disappears, skipping tiles that have disappeared {0 2 [4] 5}. Calling position() method at this point should return 4.
*/

#include <stdexcept>
#include <iostream>
#include <set>

class Platformer
{
public:
    Platformer(int n, int position)
    {
        itemPosition = position;
        for (; n > 0; n--) {
            availableFields.insert(n - 1);
        }
    }

    void jumpLeft()
    {
        std::set<int>::iterator search = availableFields.find(itemPosition);
        std::advance(search, -2);
        //remove used Field
        availableFields.erase(itemPosition);
        itemPosition = *search;
    }

    void jumpRight()
    {
        std::set<int>::iterator search = availableFields.find(itemPosition);
        std::advance(search, +2);
        //remove used Field
        availableFields.erase(itemPosition);
        itemPosition = *search;
    }

    int position()
    {
        return itemPosition;
    }

private:
    std::set<int> availableFields;
    int itemPosition;
};

#ifndef RunTests
int main()
{
    Platformer platformer(6, 3);
    std::cout << platformer.position() << std::endl; // should print 3

    platformer.jumpLeft();
    std::cout << platformer.position() << std::endl; // should print 1

    platformer.jumpRight();
    std::cout << platformer.position() << std::endl; // should print 4
}
#endif