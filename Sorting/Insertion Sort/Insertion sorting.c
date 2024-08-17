#include<stdio.h>
//For ascending order sorting
int insertionsortascend(int *arr,int size){
    int key,j;
    //Loop for passes
    for(int i=1;i<size;i++){
      key=arr[i];
      j=i-1;
      //Loop for each pass
      while(j>=0 && arr[j]>key){
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=key;
    }
}
//For descending order sorting
int insertionsortdescend(int *arr,int size){
    int key,j;
    //Loop for passes
    for(int i=1;i<size;i++){
      key=arr[i];
      j=i-1;
      //Loop for each pass
      while(j>=0 && arr[j]<key){
          arr[j+1]=arr[j];
          j--;
      }
      arr[j+1]=key;
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
    int element=10;
    printarray(arr,size);
    
    insertionsortascend(arr,size);
    printarray(arr,size);
    insertionsortdescend(arr,size);
    printarray(arr,size);
}
