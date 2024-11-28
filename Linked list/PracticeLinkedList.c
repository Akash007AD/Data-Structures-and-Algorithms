#include <stdio.h>
#include <stdlib.h.>
struct Node
{
    int data;
    struct Node *next;
};
// Traversal
void traverse(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Insertion First
struct Node *InsertFirst(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
// Insertion end
struct Node *InsertEnd(struct Node *head, int data)
{
    struct Node *ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
//Insertion Between
struct Node* InsertIndex(struct Node * head,int data,int index){
    struct Node* ptr;
    ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node* p=head;
    int i=0;
    while(i !=index-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 15;
    second->next = third;

    third->data = 20;
    third->next = fourth;

    fourth->data = 25;
    fourth->next = fifth;

    fifth->data = 30;
    fifth->next = NULL;

    traverse(head);
    head = InsertFirst(head, 5);
    traverse(head);
    head = InsertEnd(head, 35);
    traverse(head);
    head=InsertIndex(head,40,4);
    traverse(head);
    return 0;
}