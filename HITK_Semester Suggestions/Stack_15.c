#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    char *arr;
    int size;
};
struct stack* createstack(int size){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->size=size;
    s->arr=(char*)malloc(size*sizeof(char));
    return s;
}
void push(struct stack* s,char e){
    s->top++;
    s->arr[s->top]=e;
}
char pop(struct stack* s){
    char x=s->arr[s->top];
    s->top--;
    return x;
}
int isempty(struct stack* s){
    if(s->top==-1) return 1;
    else return 0;
}
int isfull(struct stack* s){
    if(s->top==s->size-1) return 1;
    else return 0;
}
int parenthesis(char* exp){
    int i=0;
    struct stack* s=createstack(strlen(exp));
    while(exp[i]!='\0'){
        if(exp[i]=='('){
            push(s,exp[i]);
        }
        if(exp[i]==')'){
            pop(s);
        }
        i++;
    }
    if(isempty(s))
        return 1;
    else
        return 0;

}
int main(){
    char exp='10+(2-3)-(4*6)';
    if(parenthesis(exp))
        printf("Parenthesis match");
    else
        printf("parenthesis not matched");

}