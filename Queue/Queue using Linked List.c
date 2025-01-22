#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;
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
void enqueue( int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}
int dequeue()
{
    int val=-1;
    struct node *ptr=f;
    if (f == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    
    display(f);
    enqueue(34);
    enqueue(10);
    enqueue(34);
    enqueue(10);
    enqueue(34);
    enqueue(10);
    display(f);
    dequeue();
    display(f);
}