
#include <stdio.h>
void mergesort(int *arr,int size1,int *brr,int size2,int *crr){
    int size=size1+size2;
    int i=0,j=0,k=0;
    while(i<size1  && j<size2 ){
        if(arr[i]<brr[j]){
            crr[k]=arr[i];
            i++;
            k++;
        }
        else if(arr[i]>brr[j]){
           crr[k]=brr[j];
            j++;
            k++;
        }
    }
    while(i<size1){
        crr[k]=arr[i];
            i++;
            k++;
    }
    while(j<size2){
         crr[k]=brr[j];
            j++;
            k++;
    }
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[]={2,4,6,8,10,12,14,16};
    int size1=sizeof(arr)/sizeof(arr[0]);
    int brr[]={1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};
    int size2=sizeof(brr)/sizeof(brr[0]);
    int size=size1+size2;
    int crr[size];
    mergesort(arr,size1,brr,size2,crr);
    printarray(crr,size);
    

    return 0;
}