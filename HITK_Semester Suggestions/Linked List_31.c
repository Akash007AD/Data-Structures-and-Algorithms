/*Write an algorithm/C-like pseudo code to delete the last element from a circular singly linked list.
What is the time complexity of this operation?
*/
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
    struct node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr->next!=head);
    printf("\n");
}
struct node* deletelast(struct node* head){
    struct node* p=head;
    struct node* q=head->next;
    while(q->next!=head){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;

}
int main(){
    struct node* head=createnode(5);
    struct node* first=createnode(10);
    struct node* second=createnode(15);
    struct node*  third=createnode(20);
    head->next=first;
    first->next=second;
    second->next=third;
    third->next=head;
    display(head);
    head=deletelast(head);
    display(head);
}