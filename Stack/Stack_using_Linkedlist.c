#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};

int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else {
        return 0;
    }
}
int isFull(struct Node* top){
    struct Node* n=(struct Node*) malloc(sizeof(struct Node));
    if (n==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

struct Node * push(struct Node* top,int x){
    if(isFull(top)){
        printf("Stack Overflow");
    }
    else{
        struct Node* n=(struct Node*) malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
    }
}
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow");
    }
    else{
        struct Node* n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int peek(struct Node* top,int pos){
    struct Node *ptr=top;
    for(int i =0;(i<pos-1 && ptr != NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL)
        return ptr->data;
    else    
        return -1;
}

int stackTop(struct Node *top ){
    return top->data;
}
int stackBottom(struct Node *top){
    struct Node *ptr=top;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    return ptr->data;
}
void traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d \n",ptr->data);
        ptr =ptr->next;
    }
}
int main(){
    struct Node * top =NULL;
    top=push(top,78);
    top=push(top,68);
    top=push(top,58);
    top=push(top,48);
    top=push(top,38);
    top=push(top,28);
    traverse(top);
    int element=pop(&top);
    printf("Popped Element is %d\n",element);
    traverse(top);
    int num=peek(top,3);
    printf("Element at position 3 is %d \n",num);
    printf("stackTop is %d\n",stackTop(top));
    printf("stackBottom is %d\n",stackBottom(top));

    return 0;
 }