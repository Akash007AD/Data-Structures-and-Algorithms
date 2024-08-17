#include<stdio.h>
void sortascending(int *arr,int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void sortdescending(int *arr,int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void printarray(int *arr,int size){
    for(int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
        printf("\n");
}
int main(){
    int arr[]={1,3,5,7,9,2,4,6,8};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,size);
    sortascending(arr,size);
    printarray(arr,size);
    sortdescending(arr,size);
    printarray(arr,size);
}