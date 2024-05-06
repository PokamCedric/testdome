/*
A tree is an abstract data structure consisting of nodes. Each node has only one parent node and zero or more child nodes. Each tree has one special node, called a root, which has no parent node. A node is called an internal node if it has one or more children. 

A tree can be represented by an array P where P[i] is the parent of node i. For the root node r, P[r] equals -1.

Write a function that, efficiently with respect to time used, counts the number of internal nodes in a given tree.

For example, the tree represented by the array {1, 3, 1, -1, 3} has 5 nodes, 0 to 4, of which 2 nodes are internal nodes (only nodes 1 and 3 have children).
*/


#include <stdlib.h>
#include <stdio.h>

// Count all the distinct elements and remove the root parent -1
int count_internal_nodes(const int *tree, int tree_size)
{
    int res = 1;
 
    // Pick all elements one by one
    for (int i = 1; i < tree_size; i++) {
        int j = 0;
        for (j = 0; j < i; j++)
            if (tree[i] == tree[j])
                break;
 
        // If not printed earlier, then print it
        if (i == j)
            res++;
    }
    return res -1;
}

#ifndef RunTests
int main()
{
    int tree[] = { 1, 3, 1, -1, 3 };
    printf("%d", count_internal_nodes(tree, 5));
}
#endif