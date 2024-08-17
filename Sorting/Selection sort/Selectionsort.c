#include<stdio.h>
void selectionsort(int *arr,int size){
    int indexofmin, temp;
    for(int i=0;i<size;i++){
        indexofmin=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[indexofmin]){
                indexofmin=j;
            }
        }
         //Swap arr[i] and arr[indexofmin]
                    temp=arr[i];
                    arr[i]=arr[indexofmin];
                    arr[indexofmin]=temp;
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
     selectionsort(arr,size);
     printarray(arr,size);
     
}