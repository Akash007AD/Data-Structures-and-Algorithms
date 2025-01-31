#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

struct queue* createqueue(int size){
    struct queue * q=(struct queue*)malloc(sizeof(struct queue));
    q->size=size;
    q->arr=(int*)malloc(q->size*sizeof(int));
    q->f=q->r=-1;
    return q;
}
int isfull(struct queue *q){
    if(q->r==q->size-1) return 1;
    else return 0;
}
int isempty(struct queue* q){
    if (q->r==-1) return 1;
    else return 0;
}
void enqueue(struct queue* q,int data){
    
    if(!isfull(q)){
    q->r++;
    q->arr[q->r]=data;
    }
}
int dequeue(struct queue* q){
    int a=-1;
    if(!isempty(q)){
        q->f++;
        a=q->arr[q->f];
        return a;
    }
}
void display(struct queue* q){
    for(int i=0;i<=q->r;i++){
        printf("%d ",q->arr[i]);
    }
}
void check(struct queue *q){
    if(isfull(q)) printf("\nQueue is full");
    else if (isempty(q)) printf("\nQueue is empty");
    else printf("\nQueue has %d elements and %d vacant spaces",(q->r)+1,(q->size)-(q->r)-1);
}
int main(){
    struct queue *q=createqueue(100);
    check(q);
    for(int i =1 ;i<=10;i++){
        enqueue(q,i);
        
    }
    check(q);
   
}