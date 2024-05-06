/*
You are holding one link of a chain in your hand. Implement function longer_side to find which side of the chain, relative to the link you are holding, has more links.

If the left side has more links return side_left, if the right side has more links return side_right, and if both sides have an equal number of links or if the chain
is a closed loop, return side_none. For example, for the code below, the output should be 1 because longer_side returns side_right:

ChainLink left = {NULL, NULL};
ChainLink middle = {NULL, NULL};
ChainLink right = {NULL, NULL};
append(&left, &middle);
append(&middle, &right);
printf("%d\n", longer_side(&left) == side_right);

*/

#include <stdio.h>

enum side {side_none, side_left, side_right};

typedef struct ChainLink
{
    struct ChainLink* left;
    struct ChainLink* right;
} ChainLink;

void append(ChainLink* base, ChainLink* link)
{
   base->right = link;
   link->left = base;
}


int detectCycle(ChainLink* head)
{
    if (head == NULL || head->left == NULL)
    {
        return 0;
    }

    //  Slow Pointer - This will be incremented by 1 Nodes.
    ChainLink* slow = head;
    //  Fast Pointer  - This will be incremented by 2 Nodes.
    ChainLink* fast = head->left;

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

int count_distance(ChainLink* link, int isLeft)
{
    int h = 0;
    if (link != NULL) {
        if (detectCycle(link)) {
            return 0;
        }
        if (isLeft) {
            h = count_distance(link->left, isLeft);
        }
        else {
            h = count_distance(link->right, isLeft);
        }
        h++;
    }
    return h;
}

enum side longer_side(ChainLink* link)
{

    int lHeight = count_distance(link->left, 1);
    int rHeight = count_distance(link->right, 0);

    enum side longerSide = side_none;
    if (lHeight > rHeight) {
        longerSide = side_left;
    }
    else if (rHeight > lHeight) {
        longerSide = side_right;
    }
    return longerSide;
}


#ifndef RunTests
int main()
{
    ChainLink left = {NULL, NULL};
    ChainLink middle = {NULL, NULL};
    ChainLink right = {NULL, NULL};

    append(&left, &middle);
    append(&middle, &right);

    printf("%d\n", longer_side(&right) == side_left);
}
#endif