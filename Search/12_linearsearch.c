#include<stdio.h>
int linearsearch(int arr[],int element,int length){
    for(int i=0;i<length;i++){
        if (arr[i]==element){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[10]={4,6,15,8,7,2,93};
    int size=sizeof(arr)/sizeof(arr[0]);
    int element=4;
    int index=linearsearch(arr,element,size);
    printf("Index of the element %d is %d",element,index);
}