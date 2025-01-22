#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}
void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n");
}
struct node *insertfirst(struct node *head, int data)
{
    struct node *ptr = createnode(data);
    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    return head;
}
struct node *insertend(struct node *head, int data)
{
    struct node *ptr = createnode(data);
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->prev = temp;
    return head;
}
struct node *insertindex(struct node *head, int index, int data)
{
    struct node *ptr = head;
    struct node *node = createnode(data);
    if (index == 0)
    {
        return insertfirst(head, data);
    }

    int i = 0;
    while (ptr != NULL && i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        printf("index out of bound\n");
        return head;
    }
    node->prev = ptr;
    node->next = ptr->next;
    ptr->next->prev = node;
    ptr->next = node;
    return head;
}
struct node* insertaftervalue(struct node* head, int value, int data) {
    struct node* p = head;
    
    while (p != NULL && p->data != value) {  
        p = p->next;
    }

    if (p == NULL) {  
        printf("Value %d not found in the list.\n", value);
        return head;
    }

    struct node* ptr = createnode(data);
    ptr->next = p->next;
    ptr->prev = p;
    
    if (p->next != NULL) {  
        p->next->prev = ptr;
    }
    p->next = ptr;
    
    return head;
}
int main()
{
    struct node *head = createnode(5);
    struct node *second = createnode(10);
    struct node *third = createnode(15);
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    display(head);
    head = insertfirst(head, 2);
    display(head);
    head = insertend(head, 20);
    display(head);
    head = insertindex(head, 12, 1);
    display(head);
    head=insertaftervalue(head,10,13);
    display(head);
}