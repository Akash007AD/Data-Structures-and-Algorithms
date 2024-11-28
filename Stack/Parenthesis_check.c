#include<stdio.h>
#include<stdlib.h>
struct stack {
    int size;
    int top;
    char* arr;
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
void push(struct stack * ptr,char element){
    if(isfull(ptr)){
        printf("Stack Overflow!!\n");
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=element;
    }
}
int pop(struct stack * ptr){
    if(isempty(ptr)){
        printf("Stack Underflow!!\n");
        return -1;
    }
    else{
        char value=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return value;
    }
}
int parenthesisMatch(char * exp){
    struct stack * sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc (sp->size * sizeof(char));
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,'(');
        }
        else if(exp[i]==')'){
            if(isempty(sp)){
                return 0;
            }
            else{
                pop(sp);
            }
        }
    }
    if(isempty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    char *exp="10+(2*5/7)";
   
    if(parenthesisMatch(exp)){
        printf("Parenthesis is matching \n");
        
    }
    else{
        printf("Parenthesis is not matching \n");
    }
    
    return 0;
}