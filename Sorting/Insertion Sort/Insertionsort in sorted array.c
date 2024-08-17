#include<stdio.h>
int insertionsort(int *arr,int element,int size){
    for(int i=size-1;i>=0;i--){
        
        if(arr[i]>element){
            arr[i+1]=arr[i];
            arr[i]=element;
        }
    }
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={7,9,10,14,20};
    int size=sizeof(arr)/sizeof(arr[0]);
    int element=15;
    printarray(arr,size);
    size++;
    insertionsort(arr,element,size);
    printarray(arr,size);
}