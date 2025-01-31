/*Given a singly-linked list with an odd number of elements, develop a pseudo-code or C-code to
split it into two nearly equal sub-lists — one for the front half, and the other for the back half. The
extra element should go in the front list.*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    return node;
}
void *half_divisor(struct node *head, struct node **first_half, struct node **second_half)
{
    struct node *ptr = head;
    int len = 1;
    while (ptr->next != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    int half_count = 0;
    struct node *half = head;
    while (half_count != len / 2)
    {
        half = half->next;
        half_count++;
    }
    *first_half = head;
    *second_half = half->next;
    half->next = NULL;
}
void display(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
int main()
{
    struct node *head = createnode(5);
    struct node *first = createnode(10);
    struct node *second = createnode(15);
    struct node *third = createnode(20);
    struct node *fourth = createnode(25);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    printf("Original Linked List: ");
    display(head);
    struct node *first_half = NULL;
    struct node *second_half = NULL;

    half_divisor(head, &first_half, &second_half);

    printf("First half: ");
    display(first_half);

    printf("Second half: ");
    display(second_half);
}