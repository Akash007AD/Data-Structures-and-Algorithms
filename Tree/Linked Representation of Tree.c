#include<stdio.h>
#include<stdlib.h>

// Defining the structure of a node in the binary tree
struct node{
    int data;                // Data part of the node
    struct node* left;       // Pointer to the left child
    struct node* right;      // Pointer to the right child
};

// Function to create a new node with given data
struct node* createnode(int data){
    struct node* node;                           // Declare a pointer for a new node
    node = (struct node *)malloc(sizeof(struct node)); // Allocate memory for the node
    node->data = data;                           // Assign data to the node
    node->left = NULL;                           // Initialize left child as NULL
    node->right = NULL;                          // Initialize right child as NULL
    return node;                                 // Return the created node
}

int main(){
    // Manually creating nodes using malloc
    struct node* p;
    p = (struct node *)malloc(sizeof(struct node)); // Allocate memory for node p
    p->data = 2;                                    // Assign value 2 to node p
    p->left = NULL;                                 // Initialize left child as NULL
    p->right = NULL;                                // Initialize right child as NULL

    struct node* p1;
    p1 = (struct node *)malloc(sizeof(struct node)); // Allocate memory for node p1
    p1->data = 3;                                    // Assign value 3 to node p1
    p1->left = NULL;                                 // Initialize left child as NULL
    p1->right = NULL;                                // Initialize right child as NULL

    struct node* p2;
    p2 = (struct node *)malloc(sizeof(struct node)); // Allocate memory for node p2
    p2->data = 4;                                    // Assign value 4 to node p2
    p2->left = NULL;                                 // Initialize left child as NULL
    p2->right = NULL;                                // Initialize right child as NULL

    // Connecting nodes to form a binary tree
    p->left = p1;  // Set p1 as the left child of p
    p->right = p2; // Set p2 as the right child of p

    // Creating nodes using the createnode() function
    struct node* p3 = createnode(2);  // Create a node with data 2
    struct node* p4 = createnode(3);  // Create a node with data 3
    struct node* p5 = createnode(4);  // Create a node with data 4

    // Connecting nodes created with createnode() to form a binary tree
    p3->left = p4;  // Set p4 as the left child of p3
    p3->right = p5; // Set p5 as the right child of p3

    return 0; // End of program
}
