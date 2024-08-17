#include<stdio.h>
int bubblesort(int *arr,int size){
    int temp;
    for(int i=0;i<=size-1;i++){ /*For number of pass*/
        for(int j=0;j<=size-1-i;j++){ /*For comparison in in each pass*/
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

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
    int arr[]={10,6,13,45,2,34};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,size);
    printf("\n");
    bubblesort(arr,size);
     printarray(arr,size);
     

}