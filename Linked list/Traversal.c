#include <stdio.h>
#include <stdlib.h>
 struct Node{
     int data;
     struct Node * next;
 };
 void linkedlist_traversal_pointer(struct Node* ptr){
     int i =1;
     while(ptr!=NULL){
     printf("Element %d: %d ->",i,ptr->data);
     i++;
     ptr=ptr->next;

     }
     printf("NULL");
 }
 int main(){
     struct Node* head;
     struct Node* second;
     struct Node* third;
     struct Node* fourth;
     //Memory allocation from heap by dynamic memory allocation
     head=(struct Node*) malloc (sizeof(struct Node));
     second=(struct Node*) malloc (sizeof(struct Node));
     third=(struct Node*) malloc (sizeof(struct Node));
     fourth=(struct Node*) malloc (sizeof(struct Node));
     //Allocating head data and linking first node with second node
     head->data=7;
     head->next=second;
     //Allocating second data and linking second node with third node
     second->data=10;
     second->next=third;
     //Allocating third data and linking third node with fourth node
     second->data=10;
     third->data=17;
     third->next=fourth;
     //Allocating fourth data and linking fourth node with NULL to terminate 
     fourth->data=77;
     fourth->next=NULL;
     
     linkedlist_traversal_pointer(head);
     
     
     
 }