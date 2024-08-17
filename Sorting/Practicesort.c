#include<stdio.h>
int sort(int *arr,int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i<j){
                if(arr[i]>arr[j]){
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
            }
            
        }
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
    int arr[]={7,14,2,15,3,47};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,size);
     sort(arr,size);
     printarray(arr,size);
     
}