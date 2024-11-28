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

int isBST(struct node* root){
    static struct node* prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
    
}

int main(){
   
   struct node* p=createnode(9);
   struct node* p1=createnode(4);
   struct node* p2=createnode(11);
   struct node* p3=createnode(2);
   struct node* p4=createnode(7);
   struct node* p5=createnode(15);
   struct node* p6=createnode(5);
   struct node* p7=createnode(8);
   struct node* p8=createnode(14);
   
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    p2->right=p5;
    p4->left=p6;
    p4->right=p7;
    p5->left=p8;
    // printf("Preorder:");
    // preorder(p);
    // printf("\n");
    // printf("Postorder:");
    // postorder(p);
    // printf("\n");
    printf("Inorder:");
    inorder(p);
    printf("\n");
    if (isBST(p))
        printf("BST");
    
    else
        printf("Not BST");
    
    return 0;
}