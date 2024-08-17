#include<stdio.h>
int partition(int *arr,int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }while(i<j);
    
            temp=arr[low];
            arr[low]=arr[j];
            arr[j]=temp;
            return j;
}
void quicksort(int *arr,int low,int high){
    int partitionindex;
    if(low<high){
        partitionindex=partition(arr,low,high);
        quicksort(arr,low,partitionindex-1);
        quicksort(arr,partitionindex+1,high);
        
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
    quicksort(arr,0,size-1);
    printarray(arr,size);
     
}
/*
//int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3*/