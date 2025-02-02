/* Consider a binary search tree with n (i.e., n >= 0) nodes, which has been constructed using linked
representation of tree, where the structure of each tree node has three components: key value/
data, pointer to left subtree and pointer to right subtree.

Suggest an algorithm (/ pseudo code/ C-code) of a function (or procedure) which will delete a

given key value from the binary search tree, provided it is found in the tree*/

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
void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
   
}


struct node* search(struct node* root,int key){
    struct node* prev=NULL;
    if(root==NULL) return NULL;
    if(key==root->data) return root;
    else if(key<root->data) return search(root->left,key);
    else return search(root->right,key);
}
struct node* inOrderPredecessor(struct node* root){
    root=root->left;
    while(root->right!=NULL) root=root->right;
    return root;
}
struct node* deletenode(struct node* root,int key){
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(key<root->data){
        root->left=deletenode(root->left,key);
    }
    else if(key>root->data){
        root->right=deletenode(root->right,key);
    }
    else{
        struct node* iPre=inOrderPredecessor(root);
        root->data=iPre->data;
        root->left=deletenode(root->left,iPre->data);
    }
    return root;
}
int height(struct node* root){
    if(root==NULL) return -1;
    int leftheight=height(root->left);
    int rightheight=height(root->right);
    return (leftheight > rightheight ? leftheight : rightheight) + 1;
}
int main() {
   struct node* root=NULL;
    
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 35);
    root = insert(root, 45);
    root = insert(root, 55);
    root = insert(root, 65);
    root = insert(root, 75);
    root = insert(root, 85);

    printf("Inorder Traversal of the Tree: ");
    inorder(root);
    printf("\n");

    int key = 40;
    printf("Height of the tree is %d\n", height(root));

    root=deletenode(root,35);
    inorder(root);
    
}