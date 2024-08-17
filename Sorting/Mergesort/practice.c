#include<stdio.h>
void merge(int *arr,int low,int mid,int high){
    int brr[high+1];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
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
    for(int i=low;i<=high;i++){
        arr[i]=brr[i];
    }
}
void mergesort(int *arr,int low,int high){
    int mid;
    if(low<high){
       mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
}
void printarray(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]={4,1,3,5,2,7,10,26,9,12,14};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,size-1);
    printarray(arr,size);
}