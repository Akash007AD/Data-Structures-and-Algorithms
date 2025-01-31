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
}
int main(){
    int num=123456;
    int rev_num=0;
    for(int i=0;i<6;i++){
        rev_num=(rev_num*10)+(num%10);
        num=num/10;
    }
    
    for(int i=1;i<=6;i++){
        int n=rev_num%10;
        struct node* head=createnode(n);
        display(head);
        rev_num=rev_num/10;
    }
}