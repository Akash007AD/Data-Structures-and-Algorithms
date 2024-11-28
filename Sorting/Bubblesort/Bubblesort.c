// Online C compiler to run C program online
#include <stdio.h>
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int bubblesort(int *arr,int size){
    int comp=0;
    for (int i =0;i<=size-1;i++){
        int temp;
        for(int j =0;j<=size-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                comp++;
            }
            comp++;
        }
 
    }
    printf("Number of comparisons: %d\n",comp);
    printf("Sorted array is: \n");
    printarray(arr,size);
    
}

int main() {
    int arr[]={10,5,20,25,1};
    bubblesort(arr,5);
    
    return 0;
}