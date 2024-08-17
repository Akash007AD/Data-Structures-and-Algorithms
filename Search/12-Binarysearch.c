#include<stdio.h>
int binarysearch(int arr[],int size,int element){
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high){
    mid=(low+high)/2;
    if(arr[mid]==element){
        return mid;
    }
    else if(arr[mid]<element){
        low=mid+1;
    }
    else if(arr[mid]>element){
        high=mid-1;
    }
}
    return -1;
}
int main(){
    int arr[10]={2,4,6,8,10,12,14,16};
    int size=sizeof(arr)/sizeof(arr[0]);
    int element=14;
    int index2=binarysearch(arr,size,element);
    printf("Index of the element %d is %d",element,index2);
}