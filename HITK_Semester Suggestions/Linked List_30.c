/*Write the pseudo code to insert an element into a singly linked list at a given position. Take
appropriate measure when the list is empty or if the given position does not exist in the list. */

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
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL");
    printf("\n");
}
struct node* insertfirst(struct node* head,int data){
    struct node* node=createnode(data);
    node->next=head;
    return node;
}
struct node* insertindex(struct node* head,int data,int index){
    struct node* node=createnode(data);
    struct node* p=head;
    int i=0;
    if(head==NULL){
        if (index==0){
            return insertfirst(head,data);
        }
        else{
            printf("Invalid index,Emply LL\n");
            free(node);
            return head;
        }
    }
        
    if(index==0 ){
        return insertfirst(head,data);
    }
    while(p!=NULL && i!=index-1){
        p=p->next;
        i++;
    }
    if(p==NULL){
        printf("Invalid Index .Out of bound\n");
        free(node);
        return head;
    }
    node->next=p->next;
    p->next=node;
    return head;
}
int main(){
    struct node* head=createnode(15);
    struct node* first=createnode(10);
    struct node* second=createnode(5);
    struct node*  third=createnode(15);
    head->next=first;
    first->next=second;
    second->next=third;
    display(head);
    head=insertfirst(head,2);
    display(head);
    head=insertindex(head,7,10);
    display(head);
}