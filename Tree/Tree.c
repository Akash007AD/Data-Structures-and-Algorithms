#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
void inorder(struct node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root){
    if (root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
int main(){
    struct node* a=createnode(4);
    struct node* b=createnode(2);
    struct node* c=createnode(6);
    struct node* d=createnode(1);
    struct node* e=createnode(3);
    struct node* f=createnode(5);
    struct node* g=createnode(7);
    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    printf("Inorder:");
    inorder(a);
    printf("\n");
    printf("Preorder:");
    preorder(a);
    printf("\n");
    printf("Postorder:");
    postorder(a);
    printf("\n");

}