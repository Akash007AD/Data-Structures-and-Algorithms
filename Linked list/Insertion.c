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
//inserting a node at the first position as new head
struct Node * Insertfirst(struct Node * head,int data){
    struct Node * ptr;//Declaring a new node
    ptr=(struct Node *)malloc(sizeof(struct Node));//Allocating space from Heap
    ptr->next=head;//New node will  be in first as head and its next will be to the old head
    ptr->data=data;//assigning value in the node 
    return ptr;
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

//Inserting  a new node at the end of the linked list 
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
//Inserting  a new node in between a node in the linked list 
struct Node * Insert_between_nodes(struct Node * head,struct Node * prevnode,int data ){
    struct Node * ptr;
    ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
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
    /*Element: 10 
    Element: 15 
    Element: 20 */
    printf("\n");
    head= Insertfirst(head,50);
    traverse(head);
    printf("\n");
    /*Element: 50 
    Element: 10 
    Element: 15 
    Element: 20 
    */
    head= Insertinbetween(head,100,1);
    traverse(head);
    printf("\n");
    /*Element: 50 
    Element: 100 
    Element: 10 
    Element: 15 
    Element: 20 */
    head= Insertend(head,75);
    traverse(head);
    printf("\n");
    /*Element: 50 
    Element: 100 
    Element: 10 
    Element: 15 
    Element: 20 
    Element: 75 */
    head=  Insert_between_nodes(head,second,150);
    traverse(head);
    printf("\n");
    /*
    Element: 50 
    Element: 100 
    Element: 10 
    Element: 15 
    Element: 150 
    Element: 20 
    Element: 75 */
}