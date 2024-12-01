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

// Function to insert a key into the BST
void insertion(struct node* root, int key){
    struct node* prev = NULL; // To keep track of the parent node
    while(root != NULL){
        prev = root; // Update parent to the current root
        if(key == root->data){ 
            return; // Key already exists; no insertion needed
        }
        else if(key < root->data){ 
            root = root->left; // Traverse to the left subtree
        }
        else{
            root = root->right; // Traverse to the right subtree
        }
    }
    struct node* new = createnode(key); // Create a new node for the key
    if(key < prev->data){
        prev->left = new; // Attach new node as the left child
    }else{
        prev->right = new; // Attach new node as the right child
    }
}

// Helper function to find the in-order predecessor of a node
struct node* inOrderPredecessor(struct node* root){
    root = root->left; // Move to the left subtree
    while(root->right != NULL){ 
        root = root->right; // Move to the rightmost node
    }
    return root; // Return the in-order predecessor
}

// Function to delete a key from the BST
struct node* deletion(struct node* root, int key){
    struct node* iPre;
    
    // Base case: If the tree is empty
    if (root == NULL){
        return NULL;
    }

    // If the node to delete is a leaf node (no children)
    if(root->left == NULL && root->right == NULL){
        free(root); // Free the memory of the node
        return NULL; // Return NULL to the parent
    }

    // Recursively search for the node to be deleted
    if(key < root->data){
        root->left = deletion(root->left, key); // Move to the left subtree
    }
    else if(key > root->data){
        root->right = deletion(root->right, key); // Move to the right subtree
    }
    else {
        // Node with two children: Find the in-order predecessor
        iPre = inOrderPredecessor(root);
        root->data = iPre->data; // Replace current node's data with predecessor's data
        root->left = deletion(root->left, iPre->data); // Delete the predecessor
    }

    return root; // Return the updated root
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
    
    // Performing inorder traversal before any modifications
    printf("Inorder:");
    inorder(p);
    printf("\n");
    
    // Inserting a new key into the BST
    insertion(p, 6);
    printf("Inorder after insertion:");
    inorder(p);
    printf("\n");

    // Deleting a node with the key 2
    deletion(p, 2);
    printf("Inorder after deletion:");
    inorder(p);
    printf("\n");

    return 0; 
}
