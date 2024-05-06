#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

struct Node* search(const struct Node *root, const int number)
{
    if (root == NULL)
        return NULL;
    if (number == root->value)
       return root;
    if (number < root->value)
        return search(root->left, number);
    if (number > root->value)
        return search(root->right, number);
}

int contains(const Node *root, int value)
{
    struct node* res = search(root, value);
    
    if(res==NULL) return 0;
    if(res!=NULL) return 1;
}


#ifndef RunTests
int main()
{
    Node n1 = {.value=1, .left=NULL, .right=NULL};
    Node n3 = {.value=3, .left=NULL, .right=NULL};
    Node n2 = {.value=2, .left=&n1, .right=&n3};

    printf("%d", contains(&n2, 3));
}
#endif