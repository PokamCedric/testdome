/*
A tree is an abstract data structure consisting of nodes. Each node has only one parent node and zero or more child nodes.
Each tree has one special node, called a root, which has no parent node. A node is called a leaf if it has no child nodes.
The height of a tree is the largest distance (number of parent-child connections) from the root to a leaf.

Write a function that calculates the height of a given tree. For example, the tree below has a height of 2 since the longest distance
(number of parent-child connections) from the root to a leaf is 2 (the connections are the root to a node and then the node to leaf 1):

Node* leaf1 = new Node(NULL, NULL);
Node* leaf2 = new Node(NULL, NULL);
Node* node = new Node(leaf1, NULL);
Node* root = new Node(node, leaf2);
*/

#include <stdio.h>

typedef struct Node
{
    struct Node* left_child;
    struct Node* right_child;
} Node;


int countNode(const Node* node)
{
    int h = 0, lHeight = 0, rHeight = 0;

    if(node != NULL){
        if (node->left_child != NULL)
        {
            lHeight = countNode(node->left_child);
        }
        if (node->right_child != NULL)
        {
            rHeight = countNode(node->right_child);
        }
    }

    int maxHeight = (lHeight > rHeight)?lHeight :rHeight ;
    h = maxHeight + 1;
    return h;
}

int height(const Node* node)
{
    return countNode(node) -1;
}
  
#ifndef RunTests
int main()
{
    Node leaf_1 = {NULL, NULL};
    Node leaf_2 = {NULL, NULL};
    Node node = {&leaf_1, NULL};
    Node root = {&node, &leaf_2};
    printf("%d\n", height(&root));
}
#endif