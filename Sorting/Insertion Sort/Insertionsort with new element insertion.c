#include<stdio.h>
//For ascending order sorting and inserting new element
int insertionsortascend(int *arr,int element,int size){
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
//For descending order sorting and inserting new element
int insertionsortdescend(int *arr,int element,int size){
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
    size++;
    insertionsortascend(arr,element,size);
    printarray(arr,size);
    insertionsortdescend(arr,element,size);
    printarray(arr,size);
}
