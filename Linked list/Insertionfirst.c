#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void traverse(struct Node *ptr){
    while(ptr != NULL){
        printf("Element: %d \n",ptr->data);
        ptr =ptr->next;
    }
}
//Inserting a node at the first position as new head
struct Node * Insertfirst(struct Node * head,int data){
    struct Node * ptr;//Declaring a new node
    ptr=(struct Node *)malloc(sizeof(struct Node));//Allocating space from Heap
    ptr->next=head;//New node will  be in first as head and its next will be to the old head
    ptr->data=data;//assigning value in the node 
    return ptr;
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    
    head->data=10;
    head->next=second;
    
    second->data=15;
    second->next=third;
    
    third->data=20;
    third->next=NULL;
    
    traverse(head);
    printf("\n");
    head= Insertfirst(head,50);
    traverse(head);
    
}