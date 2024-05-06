/* ----Chain Link
You are holding one link of a chain in your hand. Implement method longerSide to find which side of the chain, relative to the link you are holding, has more links.

If the left side has more links return Side::LEFT, if the right side has more links return Side::RIGHT, and if both sides have an equal number of links
or if the chain is a closed loop, return Side::NONE. For example, for the code below, the output should be Side::RIGHT (or 2):

ChainLink* left = new ChainLink();
ChainLink* middle = new ChainLink();
ChainLink* right = new ChainLink();
left->append(middle);
middle->append(right);
std::cout << left->longerSide();
*/

#include <stdexcept>
#include <iostream>

enum Side { NONE, LEFT, RIGHT };

class ChainLink
{
public:
    ChainLink* getLeft() const{
        return left;
    }
    ChainLink* getRight() const{
        return right;
    }

    void append(ChainLink* rightPart)
    {
        if (this->right != NULL)
            throw std::logic_error("Link is already connected.");

        this->right = rightPart;
        rightPart->left = this;
    }

    Side longerSide()
    {
        int lHeight = count_distance(this->getLeft(), 1);
        int rHeight = count_distance(this->getRight(), 0);

        enum Side longerSide = NONE;
        if (lHeight > rHeight) {
            longerSide = LEFT;
        }
        else if (rHeight > lHeight) {
            longerSide = RIGHT;
        }
        return longerSide;
    }

private:
    ChainLink* left;
    ChainLink* right;
  
    int count_distance(ChainLink* link, int isLeft)
    {
        int h = 0;
        if (link != NULL) {
            if (detectCycle()) {
                return 0;
            }
            if (isLeft) {
                h = count_distance(link->getLeft(), isLeft);
            }
            else {
                h = count_distance(link->getRight(), isLeft);
            }
            h++;
        }
        return h;
    }

    int detectCycle()
    {
        if (this == NULL || this->getLeft() == NULL)
        {
            return 0;
        }

        //  Slow Pointer - This will be incremented by 1 Nodes.
        ChainLink* slow = this;
        //  Fast Pointer  - This will be incremented by 2 Nodes.
        ChainLink* fast = this->getLeft();

        while (slow != fast)
        {
            //  We reached the end of the List and haven't found any Cycle.
            if (fast == NULL || fast->left == NULL)
            {
                return 0;
            }
            slow = slow->left;
            fast = fast->left->left;
        }

        //  We found a Cycle.
        return 1;
    }

};

#ifndef RunTests
int main()
{
    ChainLink* left = new ChainLink();
    ChainLink* middle = new ChainLink();
    ChainLink* right = new ChainLink();
    left->append(middle);
    middle->append(right);

    std::cout << left->longerSide();
}
#endif