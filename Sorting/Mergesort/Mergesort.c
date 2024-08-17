
#include <stdio.h>
void mergesort(int *arr,int low,int mid,int high){
    int i=low,j=mid+1,k=low;
    int brr[high+1];
    while(i<=mid  && j<=high){
        if(arr[i]<arr[j]){
            brr[k]=arr[i];
            i++;
            k++;
        }
        else if(arr[i]>arr[j]){
           brr[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        brr[k]=arr[i];
            i++;
            k++;
    }
    while(j<=high){
        brr[k]=arr[j];
            j++;
            k++;
    }
    for(int i =low;i<=high;i++){
        arr[i]=brr[i];
    }
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[]={7,10,12,2,4,6};
    int size=sizeof(arr)/sizeof(arr[0]);
   
    mergesort(arr,0,2,size-1);
    printarray(arr,size);
    

    return 0;
}