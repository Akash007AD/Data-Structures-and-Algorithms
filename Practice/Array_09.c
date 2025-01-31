#include<stdio.h>

// int* reverse_using_array(int* arr){
//     int size=sizeof(arr)/sizeof(arr[0]);
//     int brr[size];
//     for(int i=0;i<=size;i++){
//         arr[i]=brr[size-i];
//     }
//     return brr;
// }
void display(int* arr,int size){
    
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void reverse_without_array(int* arr,int size){
    
    int start=0;
    int end=size-1;
    while(start<end){
        int temp;
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    
}
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    display(arr,size);
    reverse_without_array(arr,size);
    display(arr,size);

}