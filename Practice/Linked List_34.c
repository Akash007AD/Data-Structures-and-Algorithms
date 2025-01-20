/*How do you merge two sorted linked lists into a single sorted linked list? Provide an algorithm
and analyze its time complexity.*/
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
struct node* sorted(struct node* head1,struct node* head2){
    struct node* new_head=NULL;
    struct node* sorting=NULL;

    if (head1==NULL) return head2;
    if(head2==NULL) return head1;

   
    if(head1->data<=head2->data){
        sorting=head1;
        head1=head1->next;
    }
    else{
        sorting=head2;
        head2=head2->next;
    }
    
    new_head=sorting;
    while(head1!=NULL && head2!= NULL){
        if(head1->data <=head2->data){
            sorting->next=head1;
            sorting=head1;
            head1=head1->next;
        }
        else{
            sorting->next=head2;
            sorting=head2;
            head2=head2->next;
        }
    }
    if(head1!=NULL) {
        sorting->next=head1;
    }
    else{
        sorting->next=head2;
    }
    
    


    return new_head;
    
}
int main(){
    struct node* head=createnode(1);
    struct node* first=createnode(3);
    struct node* second=createnode(2);
    struct node*  third=createnode(4);
    head->next=first;

    second->next=third;
    display(head);
    display(second);
    struct node* temp;
    temp=sorted(head,second);
    display(temp);
    
}