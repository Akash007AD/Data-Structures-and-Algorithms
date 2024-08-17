
#include <stdio.h>
#include<limits.h>
#include <stdlib.h>
int maximum(int *arr,int size){
    int max=INT_MIN;
    for(int i =0;i< size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;

}
void countsort(int *arr,int size){
   int max= maximum(arr,size);
   int i,j;
    int* count=(int*) malloc((max+1)*sizeof(int));
     for ( i = 0; i < max+1; i++)
     {
        count[i]=0;
     }
     for ( i = 0; i < size; i++)
     {
        count[arr[i]]+=1;
     }
     i=0;
     j=0;
     while(i<=max){
        if(count[i]>0){
            arr[j]=i;
            count[i]=count[i]-1;
            j++;
        }
        else{
            i++;
        }
     }
     free(count);

     
   
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
    countsort(arr,size);
    printarray(arr,size);
    

    return 0;
}