#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int data){
    struct node* node;
    node= (struct node *)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

void preorder(struct node* root){
    if (root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main(){
   
   struct node* p=createnode(4);
   struct node* p1=createnode(1);
   struct node* p2=createnode(6);
   struct node* p3=createnode(5);
   struct node* p4=createnode(2);
   
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    printf("Preorder:");
    preorder(p);
    printf("\n");
    printf("Postorder:");
    postorder(p);
    printf("\n");
    printf("Inorder:");
    inorder(p);
    return 0;
}