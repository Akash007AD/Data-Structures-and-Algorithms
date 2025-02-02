// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
// Structure definition for a node in a binary tree
struct node{
    int data;  // Data value stored in the node
    struct node* left;  // Pointer to the left child
    struct node* right; // Pointer to the right child
};

// Function to create a new node with given data
struct node* createnode(int data){
    struct node* node;
    node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the new node
    node->data = data; // Assign the data to the node
    node->left = NULL; // Initialize left child as NULL
    node->right = NULL; // Initialize right child as NULL
    return node; // Return the created node
}

struct node* insert(struct node* root,int key ){
    
    if(root==NULL){
        return createnode(key);
    }
    else if(key<root->data) root->left=insert(root->left,key);
    else if(key>root->data) root->right=insert(root->right,key);
    return root;
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
    printf("\n");
}
int main() {
    struct node* root=NULL;
    for(int i=1;i<=10;i++){
        root=insert(root,i);
        inorder(root);
    }
    inorder(root);
    return 0;
}