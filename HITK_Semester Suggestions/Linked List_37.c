// Write the pseudo code to determine whether a singly linked list of integers is a palindrome.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *createnode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct node *pushfront(struct node *head, int data)
{
    struct node *node = createnode(data);
    if (head != NULL)
    {
        node->next = head;
        head->prev = node;
    }
    return node;
}
struct node *pushrear(struct node *head, int data)
{
    struct node *node = createnode(data);
    if (head == NULL)
        return node;
    struct node *ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = node;
    node->prev = ptr;
    return head;
}
struct node *popfront(struct node *head)
{
    struct node *ptr = head;
    if (head != NULL)
    {
        head = head->next;
        head->prev = NULL;
        free(ptr);
        return head;
    }
}
struct node* poprear(struct node* head){
    struct node* ptr=head;
    while(ptr->next!=NULL) ptr=ptr->next;
    struct node* temp=ptr->prev;
    temp->next=NULL;
    free(ptr);
    return head;
}
int main()
{
    struct node *head = createnode(1);
    struct node *first = createnode(2);
    struct node *second = createnode(3);
    struct node *third = createnode(2);
    struct node *fourth = createnode(1);

    // Linking nodes to form a doubly linked list
    head->next = first;
    first->prev = head;
    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    display(head);
    head = pushfront(head, 4);
    display(head);
    head = pushrear(head, 4);
    display(head);
    head=popfront(head);
    display(head);
    head=poprear(head);
    display(head);
}