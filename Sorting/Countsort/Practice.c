#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int maximum(int* arr,int n){
    int max=INT_MIN;
    for(int i=0;i<n;i++){
        if(max<arr[i]) max=arr[i];
    }
    return max;
}
void countsort(int* arr,int n){
    int max=maximum(arr,n);
    //Creating Count array
    int* count=(int*)malloc((max+1)*sizeof(int));
    for(int i=0;i<max+1;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[arr[i]]+=1;
    }
    int i=0;
    int j=0;
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
}
void printarray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[]={12,14,16,15,24,2,3,4,5,6,7,8,9,10,11};
    int size=sizeof(arr)/sizeof(arr[0]);
    printarray(arr,size);
    countsort(arr,size);
    printarray(arr,size);

}