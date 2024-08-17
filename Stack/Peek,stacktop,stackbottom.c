#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int * arr;
};

int isEmpty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(struct stack * ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void check(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("The stack is Empty \n");
    }
    else if (isFull(ptr)){
        printf("The stack is Full \n");
    }
    else{
        printf("The string has %d elements \n",ptr->top+1);
    }
}
void push(struct stack * ptr,int element){
    if(isFull(ptr)){
        printf("Stack Overflow!!\n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=element;
    }
}
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow!!");
        return -1;
    }
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int stacktop(struct stack * ptr){
    return ptr->arr[ptr->top];
}
int stackbottom(struct stack * ptr){
    return ptr->arr[0];
}
int main(){
    struct stack * s=(struct stack *)malloc (sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc(s->size * sizeof(int));
    check(s);
    push(s,14);
    push(s,24);
    push(s,34);
    check(s);
    printf("Top of stack is %d \n",stacktop(s));
    printf("Bottom of stack is %d \n",stackbottom(s));
    pop(s);
    check(s);
    
}