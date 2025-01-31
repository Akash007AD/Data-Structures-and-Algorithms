/*Consider a binary tree with n (i.e., n >= 0) nodes, which has been constructed using linked
representation, where the structure of each tree node has three components: data, pointer to left
subtree and pointer to right subtree. Suggest an algorithm (/ pseudo code / C-code) of a function
(or procedure) to determine that whether the given binary tree is a Binary Search Tree (BST) or
not.

[N.B. Assume that the function has access to the root node of the given binary tree.]
What is the best case time complexity of the above algorithm?*/

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
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
            return 0;
        if (prev != NULL && root->key <= prev->key)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
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
    if(isBST(p))
        printf("\nBST");
    else 
        printf("\nNot BST");
}