#include<stdio.h>
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
 
// Inorder traversal (left -> root -> right)
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left); // Recurse for the left subtree
        printf("%d ", root->data); // Print the root node data
        inorder(root->right); // Recurse for the right subtree
    }
}

void insertion(struct node* root,int key){
    struct node* prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            return;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    struct node* new=createnode(key);
    if(key<prev->data){
        prev->left=new;
    }else{
        prev->right=new;
    }
}

int main(){
    // Creating nodes of the tree
    struct node* p = createnode(9);
    struct node* p1 = createnode(4);
    struct node* p2 = createnode(11);
    struct node* p3 = createnode(2);
    struct node* p4 = createnode(7);
    struct node* p5 = createnode(15);
    struct node* p6 = createnode(5);
    struct node* p7 = createnode(8);
    struct node* p8 = createnode(14);
    
    // Manually linking the nodes to form the tree structure
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p4->left = p6;
    p4->right = p7;
    p5->left = p8;
    
    // Performing inorder traversal
    printf("Inorder:");
    inorder(p);
    printf("\n");
    
    insertion(p,6);

    printf("Inorder:");
    inorder(p);
    printf("\n");
    return 0; 
}