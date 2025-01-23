#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == prev->data)
            return;
        else if (key < root->data)
            root = root->left;
        else if (key > root->data)
            root = root->right;
    }
    struct node *s = createnode(key);
    if (key < prev->data)
        prev->left = s;
    else if (key > prev->data)
        prev->right = s;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {

        inorder(root->left);
        printf("%d ", root->data);
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