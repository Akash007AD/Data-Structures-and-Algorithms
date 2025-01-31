#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int front;
    int rear;
    int* arr;
};
struct queue* createnode(int size){
    struct queue* queue=(struct queue*)malloc(sizeof(struct queue));
    queue->front=-1;
    queue->rear=-1;
    queue->size=size;
    queue->arr=(int*)malloc(queue->size*sizeof(int));
    return queue;
}
int isfull(struct queue* q){
    if(q->front==q->size-1) return 1;
    else return 0;
}
int isempty(struct queue* q){
    if(q->rear==-1) return 1;
    else return 0;
}
void enqueue(struct queue* q,int val){
    if(!isfull(q)){
        q->rear++;
        q->arr[q->rear]=val;
    }
}
void display(struct queue* q){
    for(int i=0;i<q->size;i++){
        printf("%d ",q->arr[i]);
    }
}
int main(){
    struct queue* q=createnode(6);
    for(int i=1;i<=6;i++){
        enqueue(q,i);
    }
    display(q);
}