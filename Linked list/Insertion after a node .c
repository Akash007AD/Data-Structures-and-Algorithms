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
    printf("\n");
    head=  Insert_between_nodes(head,second,150);
    traverse(head);
    printf("\n");
    
}