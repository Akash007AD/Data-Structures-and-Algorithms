#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
struct Node * top =NULL;
int isEmpty(struct Node* tp){
    if (tp==NULL){
        return 1;
    }
    else {
        return 0;
    }
}
int isFull(struct Node* tp){
    struct Node* n=(struct Node*) malloc(sizeof(struct Node));
    if (n==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

struct Node * push(struct Node* tp,int x){
    if(isFull(tp)){
        printf("Stack Overflow");
    }
    else{
        struct Node* n=(struct Node*) malloc(sizeof(struct Node));
        n->data=x;
        n->next=tp;
        tp=n;
    }
}
int pop(struct Node* tp){
    if(isEmpty(tp)){
        printf("Stack Underflow");
    }
    else{
        struct Node* n=tp;
        tp=tp->next;
        int x=n->data;
        free(n);
        return x;
    }
}void traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d \n",ptr->data);
        ptr =ptr->next;
    }
}
int main(){
    
    top=push(top,78);
    top=push(top,68);
    top=push(top,58);
    traverse(top);
    int element=pop(top);
    printf("Popped Element is %d\n",element);
    traverse(top);
    return 0;
 }