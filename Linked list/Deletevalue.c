#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * next;
};
struct Node * deletevalue(struct Node * head,int value){
    struct Node * p=head;
    struct Node * q=head->next;
    while(q->data!=value && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    
    if(q->data==value){
        p->next=q->next;
        free(q);
    }
    
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
    seventh->next=NULL;
    
    traverse(head);
    printf("\n");
    
   head=deletevalue(head,30);
    traverse(head);
    
}