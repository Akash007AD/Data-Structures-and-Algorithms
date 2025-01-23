/*Consider a binary tree with n (i.e., n >= 0) nodes, which has been constructed using linked
representation, where structure of each tree node has three components: data, pointer to left
subtree and pointer to right subtree. Write a recursive algorithm that will display all the keys of a
given Binary search tree in sorted (ascending) order.*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
};
struct node *createnode(int key)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->key = key;
    root->left = NULL;
    root->right = NULL;
    return root;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int main()
{
    // Creating nodes of the tree
    struct node *p = createnode(9);
    struct node *p1 = createnode(4);
    struct node *p2 = createnode(11);
    struct node *p3 = createnode(2);
    struct node *p4 = createnode(7);
    struct node *p5 = createnode(15);
    struct node *p6 = createnode(5);
    struct node *p7 = createnode(8);
    struct node *p8 = createnode(14);

    // Manually linking the nodes to form the tree structure
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p4->left = p6;
    p4->right = p7;
    p5->left = p8;

    inorder(p);
}