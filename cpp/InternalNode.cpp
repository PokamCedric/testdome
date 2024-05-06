/*
A tree is an abstract data structure consisting of nodes. Each node has only one parent node and zero or more child nodes. Each tree has one special node, called a root, which has no parent node. A node is called an internal node if it has one or more children. 

A tree can be represented by an array P where P[i] is the parent of node i. For the root node r, P[r] equals -1.

Write a function that, efficiently with respect to time used, counts the number of internal nodes in a given tree.

For example, the tree represented by the array {1, 3, 1, -1, 3} has 5 nodes, 0 to 4, of which 2 nodes are internal nodes (only nodes 1 and 3 have children).
*/

/*----Explication de Cedric

P[i] veut dire Parent du Node avec id i,

décomposons donc {1, 3, 1, -1, 3}
P[0] -> 1
P[1] -> 3
P[2] -> 1
P[3] -> -1   (n'a pas de parent) et est root
P[4] -> 3   


- les Nodes externes ne sont pas Parents donc tous 
- les nodes internes ont au moins un enfant, ils sont 1 et 3 (=> {1, 3, 1, -1, 3})

*/


#include <vector>
#include <stdexcept>
#include <iostream>
#include <set>

int countInternalNodes(const std::vector<int>& tree)
{
    std::set<int> parents(tree.begin(), tree.end());

    // Remove Parent -1
    return parents.size() -1 ;
}

#ifndef RunTests
int main()
{
    std::vector<int> tree;
    tree.push_back(1);
    tree.push_back(3);
    tree.push_back(1);
    tree.push_back(-1);
    tree.push_back(3);

    std::cout << countInternalNodes(tree);
}
#endif