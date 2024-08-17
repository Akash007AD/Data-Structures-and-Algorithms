#include<stdio.h>
//Code for printing
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
//Code for deletion
int deletion(int arr[],int size,int position){
    if(position>=size){
        printf("Deletion is not possible");
    }
    else{
        for(int i=position-1;i<size;i++){
            arr[i]=arr[i+1];
        }
    }

}
int main(){
    int arr[100]={5,10,15,20};
    int size=4;
    display(arr,size);
    deletion(arr,size,3);
    size--;
    display(arr,size);
    return 0;
}