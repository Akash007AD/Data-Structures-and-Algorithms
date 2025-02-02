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
    node->left = node->right = NULL;
    return node;
}

void insertion(struct node* root,int key){
    struct node* node=createnode(key);
    struct node* prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data) return ;
        else if (key<root->data) root=root->left;
        else root=root->right;
    }
    if(key<prev->data) prev->left=node;
    else prev->right=node;
}

// Recursive insertion function
struct node* insertion_recursive(struct node* root, int key)
{
    // Base case: If tree is empty or we reach a leaf node
    if (root == NULL) return createnode(key);
    
    // If key is smaller, insert in left subtree
    if (key < root->data)
        root->left = insertion_recursive(root->left, key);
    
    // If key is greater, insert in right subtree
    else if (key > root->data)
        root->right = insertion_recursive(root->right, key);
    
    // Return unchanged root node
    return root; 
}
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node* inOrderPredecessor(struct node* root){
    root = root->left; 
    while(root->right != NULL){ 
        root = root->right; 
    }
    return root; 
}

struct node* deletion(struct node* root, int key){
    struct node* iPre;
    
    
    if (root == NULL){
        return NULL;
    }

    
    if(root->left == NULL && root->right == NULL){
        free(root); 
        return NULL; 
    }

    
    if(key < root->data){
        root->left = deletion(root->left, key); 
    }
    else if(key > root->data){
        root->right = deletion(root->right, key); 
    }
    else {
       
        iPre = inOrderPredecessor(root);
        root->data = iPre->data; 
        root->left = deletion(root->left, iPre->data); 
    }

    return root; 
}
int main(){
    struct node* root=createnode(10);
    for(int i =0;i<=20;i++){
        root=insertion_recursive(root,i*2+3);
    }
    inorder(root);
    deletion(root,37);
    inorder(root);
}