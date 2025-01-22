#include<stdio.h>
#include<stdlib.h>
struct stack{
    int *arr;
    int size;
    int top;
};
struct stack *createstack(int size){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->size=size;
    s->top=-1;
    s->arr=(int*)malloc(size*sizeof(int));
    return s;
}
void display(struct stack* s){
    for (int i=0;i<=s->top;i++){
        printf("%d ",s->arr[i]);
    }
    printf("\n");
}
void push(struct stack* s,int data){
    s->top++;
    s->arr[s->top]=data;
}
int pop(struct stack *s){
    int temp=s->arr[s->top];
    s->top--;
    return temp;

}
struct stack* transfer(struct stack* s){
    struct stack* c=createstack(s->size);
    struct stack* temp=createstack(s->size);
    int i=s->top;
    while(i!=-1){
        int x=pop(s);
        push(temp,x);
        i--;
    }
    int j=temp->top;
    while(j!=-1){
        int y=pop(temp);
        push(c,y);
        j--;
    }
    free(temp);
    return c;
    


}
int main(){
    struct stack* s=createstack(20);
    for (int i=1;i<=10;i++){
        push(s,i);
    }
    display(s);
    pop(s);
    display(s);
    struct stack* new=createstack(s->size);
    new=transfer(s);
    display(new);
    push(s,12);
    display(s);
    
}