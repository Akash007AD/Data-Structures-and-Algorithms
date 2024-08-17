#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int * arr;
};
int isEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}
int stackcheck(struct stack * s){
    if(isEmpty(s)){
        printf("The stack is empty \n");
        
    }
    else{
        printf("The stack is not empty \n");
    }
    if(isFull(s)){
        printf("The stack is full \n");
        
    }
    else{
        printf("The stack is not full \n");
    }
}
int push(struct stack * ptr,int value){
    if(isFull(ptr)){
        printf("Stack Overflow!!\n");
        return -1;
    }
    else{
        ptr->top=ptr->top+1;
        ptr->arr[ptr->top]=value;
    }
}
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!!\n");
        return -1;
    }
    else{
        int value=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return value;
    }
}

int main(){
    struct stack * s=(struct stack*)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc (s->size * sizeof(int));
    stackcheck(s);
    push(s,4);
    stackcheck(s);
    pop(s);
    stackcheck(s);
}