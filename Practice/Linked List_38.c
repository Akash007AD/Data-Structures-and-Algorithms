//Write the pseudo code to determine whether a singly linked list of integers is a palindrome.
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
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int isPalindrome(struct node *head)
{
    int num = 0;
    struct node *ptr = head;
    while (ptr != NULL)
    {
        num = (num * 10) + ptr->data;
        ptr = ptr->next;
    }
    int temp = num;
    int pal = 0;
    while (num > 0)
    {
        pal = (pal * 10) + (num % 10);
        num = num / 10;
    }
    if (pal == temp)
        return 1;
    else
        return 0;
}
int main()
{
    struct node *head = createnode(1);
    struct node *first = createnode(2);
    struct node *second = createnode(3);
    struct node *third = createnode(2);
    struct node *fourth = createnode(1);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    if (isPalindrome(head))
        printf("Palindrome");
    else
        printf("Not palindrome");
}