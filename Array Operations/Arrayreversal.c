#include<stdio.h>
int reverse(int *arr,int size){
    int temp;
    for(int i=0;i<size/2;i++){
        temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }
}

void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={10,6,13,45,2,34};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,size);
    reverse(arr,size);
    printarray(arr,size);
    
     

}