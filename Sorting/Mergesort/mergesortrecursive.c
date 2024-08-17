
#include <stdio.h>
void merge(int *arr,int low,int mid,int high){
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
void Mergesort(int *arr,int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2; //By this recursive function we don't have to enter the midpoint by ourself,it will find the midpoint by it self and put all those element to the merge function
        Mergesort(arr,low,mid);
        Mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[]={12,14,16,15,24,2,3,4,5,6,7,8,9,10,11};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,size);
    Mergesort(arr,0,size-1);
    printarray(arr,size);
    

    return 0;
}