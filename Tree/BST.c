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

// Preorder traversal (root -> left -> right)
void preorder(struct node* root){
    if (root != NULL){
        printf("%d ", root->data); // Print the root node data
        preorder(root->left); // Recurse for the left subtree
        preorder(root->right); // Recurse for the right subtree
    }
}

// Postorder traversal (left -> right -> root)
void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left); // Recurse for the left subtree
        postorder(root->right); // Recurse for the right subtree
        printf("%d ", root->data); // Print the root node data
    }
}

// Inorder traversal (left -> root -> right)
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left); // Recurse for the left subtree
        printf("%d ", root->data); // Print the root node data
        inorder(root->right); // Recurse for the right subtree
    }
}

// Function to check if a tree is a Binary Search Tree (BST)
int isBST(struct node* root){
    static struct node* prev = NULL; // Static variable to hold the previous node during traversal
    if(root != NULL){
        if(!isBST(root->left)){ // Check the left subtree
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){ // Validate BST property
            return 0;
        }
        prev = root; // Update previous node
        return isBST(root->right); // Check the right subtree
    }
    else{
        return 1; // An empty tree is a BST
    }
}

// Function to search a key in the BST using recursion
struct node* search(struct node* root, int key){
    if(root == NULL) // If the tree is empty or key is not found
        return NULL;
    if (key == root->data) // If the key matches the root's data
        return root;
    else if (key < root->data) // If the key is smaller, search in the left subtree
        return search(root->left, key);
    else // If the key is larger, search in the right subtree
        return search(root->right, key);
}

// Function to search a key in the BST using iteration
struct node* search_iter(struct node* root, int key){
    while(root != NULL){ // Loop until root becomes NULL
        if (key == root->data){ // If key matches root's data
            return root;
        }
        else if(key < root->data){ // If the key is smaller, move to the left child
            root = root->left;
        }
        else{ // If the key is larger, move to the right child
            root = root->right;
        }
    }
    return NULL; // If key is not found
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
    
    // Checking if the tree is a BST
    if (isBST(p))
        printf("BST");
    else
        printf("Not BST");

    // Searching a key using recursion
    int x;
    printf("\nEnter your number you want to search: ");
    scanf("%d", &x);    
    if (search(p, x)){
        printf("\n%d Present in tree", x);
    }
    else{
        printf("\n%d Not present in Tree", x);
    }

    // Searching a key using iteration
    int y;
    printf("\nEnter your number you want to search: ");
    scanf("%d", &y);    
    if (search_iter(p, y)){
        printf("\n%d Present in tree", y);
    }
    else{
        printf("\n%d Not present in Tree", y);
    }

    return 0; // Indicate that the program ended successfully
}
