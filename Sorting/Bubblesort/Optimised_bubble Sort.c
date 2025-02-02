#include<stdio.h>

void bubblesort_optimised(int*arr,int size){
    int temp;
    int isSorted=0;
    for(int i=0;i< size-1;i++){
        printf("\nWorking on pass %d: ",i+1);
        isSorted=1;
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSorted=0;
            }
        }
        if(isSorted) return;
    }
}
void display(int *arr,int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={1,10,2,20,3,30,14,16,4,12,78,123,124};
    int arr_size=sizeof(arr)/sizeof(arr[0]);
    bubblesort_optimised(arr,arr_size);
    display(arr,arr_size);
    int brr[]={1,2,3,4,5,6};
    int size=sizeof(brr)/sizeof(brr[0]);
    bubblesort_optimised(brr,size);
    display(brr,size);
}