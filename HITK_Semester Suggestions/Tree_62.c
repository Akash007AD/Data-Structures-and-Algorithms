#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;  
    struct node* left;  
    struct node* right; 
};


struct node* createnode(int data){
    struct node* node;
    node = (struct node *)malloc(sizeof(struct node)); 
    node->data = data;
    node->left = NULL; 
    node->right = NULL;
    return node; 
}
struct node* insert(struct node* root,int key ){
    
    if(root==NULL){
        return createnode(key);
    }
    else if(key<root->data) root->left=insert(root->left,key);
    else if(key>root->data) root->right=insert(root->right,key);
    return root;
}

void inorder_iterative(struct node* root) {
    if (root == NULL) return;
    
    struct node* stack[100]; 
    int top = -1;             
    struct node* current = root;
    
    while (current != NULL || top != -1) {
        
        while (current != NULL) {
            stack[++top] = current;  
            current = current->left;
        }
        
        
        current = stack[top--];
        printf("%d ", current->data);
        
        
        current = current->right;
    }
}