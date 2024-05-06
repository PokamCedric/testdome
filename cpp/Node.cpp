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

#include <stdexcept>
#include <iostream>

class Node
{
public:
    Node(Node* leftChild, Node* rightChild)
    {
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }

    Node* getLeftChild() const
    {
        return this->leftChild;
    }

    Node* getRightChild() const
    {
        return this->rightChild;
    }

    int height() const
    {
        return countNode() -1;
    }

private:

    Node* leftChild;
    Node* rightChild;
    
    int countNode() const
    {
        int h = 0, lHeight = 0, rHeight = 0;
        if (getLeftChild() != NULL)
        {
            lHeight = this->getLeftChild()->countNode();
        }
        if (getRightChild() != NULL)
        {
            rHeight = this->getRightChild()->countNode();
        }
        int maxHeight = std::max(lHeight, rHeight);
        h = maxHeight + 1;
        return h;
    }

};

#ifndef RunTests
int main()
{
    Node* leaf1 = new Node(NULL, NULL);
    Node* leaf2 = new Node(NULL, NULL);
    Node* node = new Node(leaf1, NULL);
    Node* root = new Node(node, leaf2);

    std::cout << root->height();
}
#endif