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

//Inserting  a new node in between the linked list 
struct Node * Insertinbetween(struct Node *head, int data ,int index){
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;//Its a pointer which will be initialized from the head
    int i=0;
    while(i !=index-1){
        p=p->next;
        i++;
    }//Traversal of the pointer p to the position where we have to insert  the new node 
    ptr->data=data;//Assigning node's value
    ptr->next=p->next;//New node will store the same address which will be stored by pointer p
    p->next=ptr;//pointer p will store the (next) address of ptr
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
    head= Insertinbetween(head,100,1);
    traverse(head);
    
}