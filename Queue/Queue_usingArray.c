#include <stdio.h>
#include <Stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};
int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct queue *q)
{
    if (q->r == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int dequeue(struct queue *q)
{   
    int a=-1;
    if (isEmpty(q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        q->f++;
        a= q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not empty \n");
    }
    enqueue(&q, 12);
    enqueue(&q, 14);
    printf("Dequeueing element: %d \n ",dequeue(&q));//First In First Out 
    printf("Dequeueing element: %d \n ",dequeue(&q));//First In First Out 
    
    if (isEmpty(&q))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue is not empty \n");
    }
}