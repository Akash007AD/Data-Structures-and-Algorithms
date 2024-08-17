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


struct Node * Insertend(struct Node * head,int data ){
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    struct Node * p=head;
    //Traverse the pointer p to the end node 
    while (p->next!=NULL){
        p=p->next;
    }
    
    p->next=ptr;///pointer p will store the address of ptr
    ptr->next=NULL;//ptr will point to NULL to terminate the linked list
    return head;
    
    
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
   
    head= Insertend(head,75);
    traverse(head);
    
}