/*Suggest a pseudo code / C function to find the middle element of a single linked list in a single
pass. (Please note that if the list has even number of elements (n) then middle element will be the
first middle element (⌊n/2⌋).*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* createnode(int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->next=NULL;
    return node;
}
void display(struct node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
struct node* middle(struct node* head){
    struct node* p=head;
    struct node* q=head;
    while(q!=NULL && q->next!=NULL){
        p=p->next;
        q=q->next->next;
    }
    return p;
}
int main(){
    struct node* head=createnode(5);
    struct node* first=createnode(10);
    struct node* second=createnode(15);
    struct node*  third=createnode(20);
    head->next=first;
    first->next=second;
    second->next=third;
    display(head);
    struct node* mid=middle(head);
    printf("middle element: %d",mid->data);
}