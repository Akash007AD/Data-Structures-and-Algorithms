#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
struct Node * circulartraversal(struct Node * head){
    struct Node * ptr=head;
    /*while(ptr->next!= head){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("Element: %d",ptr->data);*/
    /*Alternate way*/
    do{
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr !=head);
    return head;
}
//Insertion of element in the first position of the linked list
struct Node * Insertfirst(struct Node * head,int data){
    struct Node *ptr;
    ptr=(struct Node *)malloc (sizeof(struct Node));
    ptr->data=data;
    struct Node * p=head->next;
    while(p->next!=head){
        p=p->next;
    }//Now p is pointing last node
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
    
}
void traverse (struct Node * ptr){
    while(ptr !=NULL){
    printf("Element:  %d \n",ptr->data);
    ptr=ptr->next;
}
}
int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;
    struct Node * sixth;
    struct Node * seventh;
    
    head=(struct Node *) malloc (sizeof(struct Node));
    second=(struct Node *)malloc (sizeof(struct Node));
    third=(struct Node *)malloc (sizeof(struct Node));
    fourth=(struct Node *)malloc (sizeof(struct Node));
    fifth=(struct Node *)malloc (sizeof(struct Node));
    sixth=(struct Node *)malloc (sizeof(struct Node));
    seventh=(struct Node *)malloc (sizeof(struct Node));
    
    head->data=10;
    head->next=second;
    
    second->data=15;
    second->next=third;
    
    third->data=20;
    third->next=fourth;
    
    fourth->data=25;
    fourth->next=fifth;
    
    fifth->data=30;
    fifth->next=sixth;
    
    sixth->data=35;
    sixth->next=seventh;
    
    seventh->data=40;
    seventh->next=head;
    
    // traverse(head);
    // printf("\n");
   // circulartraversal(head);
    head=Insertfirst(head,80);
    circulartraversal(head);
    
}