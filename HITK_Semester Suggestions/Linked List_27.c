/*Write a function in C/ pseudo-code to delete all the nodes that contain the certain value v, from a
singly linked list in a single pass. If there are multiple occurrences, delete all occurrences. Discuss
the worst case time complexity of the algorithm.*/

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
struct node* deletevalues(struct node* head, int value) {
    
    while (head != NULL && head->data == value) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }

    if (head == NULL) return NULL; 

    struct node* p = head;
    struct node* q = head->next;

    while (q != NULL) {
        if (q->data == value) {
            p->next = q->next;
            free(q);           
            q = p->next;       
        } else {
            p = q;            
            q = q->next;      
        }
    }

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
    head=deletevalues(head,15);
    display(head);
}
