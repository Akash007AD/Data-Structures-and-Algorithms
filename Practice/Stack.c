#include<stdio.h>
#include<stdlib.h>

//Defining a stack
struct stack{
    int top;
    int size;
    int *arr;
};
struct stack*  createStack(int size){
    struct stack*  stack=(struct stack*)malloc(sizeof(struct stack));
    stack->size=size;
    stack->top=-1;
    stack-> arr=(int*)malloc(stack->size *sizeof(int));
    return stack;
}
int isEmpty(struct stack* ptr){
    if (ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isFull(struct stack* ptr){
    if (ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack* ptr,int element){
    if(!isFull(ptr)){
        ptr->top++;
        ptr->arr[ptr->top]=element;
    }
}
int pop(struct stack* ptr){
    int val;
    if(!isEmpty(ptr)){
        val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
void check(struct stack* stack){
    if(isEmpty(stack)){
        printf("Empty Stack\n");
    }
    else if(isFull(stack)){
        printf("Stack is Full\n");
    }
    else{
        printf("Stack is not full\n");
    }
}
int main(){
    struct stack* stack=createStack(5);
    check(stack);
    push(stack,5);
    check(stack);
    return 0;
}