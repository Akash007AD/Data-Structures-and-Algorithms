#include<stdio.h>
#include<stdlib.h>
struct stack {
    int size;
    int top;
    int * arr;
};
//This function is checking if the stack is empty 
int isempty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
//This function is checking if the stack is full
int isfull(struct stack * ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    struct stack * s=(struct stack*)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int*)malloc (s->size * sizeof(int));
    //Pushing an element manually
    s->arr[0]=7;
    s->top++;//top on 0
    s->arr[1]=17;
    s->top++;//top on 1
    s->arr[2]=27;
    s->top++;//top on 2
    s->arr[3]=37;
    s->top++;//top on 3
    s->arr[4]=47;
    s->top++;//top on 4 //Now top pointer is at the end and the stack is full
    
    //Now the stack is not empty
    if(isempty(s)){
        printf("The stack is empty \n");
        
    }
    else{
        printf("The stack is not empty \n");
    }
    if(isfull(s)){
        printf("The stack is full \n");
        
    }
    else{
        printf("The stack is not full \n");
    }
    return 0;
}