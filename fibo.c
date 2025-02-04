#include<stdio.h>
void fibo(int n){
    if(n==0 || n==1) return;
    printf("Inside fibo (%d)\n",n);
    fibo(n-1);
    fibo(n-2);
    return;
}
int main(){
    fibo(4);
}