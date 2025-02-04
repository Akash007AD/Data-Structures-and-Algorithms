#include<stdio.h>
int binarysearch(int* arr,int low,int high,int num){
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==num) return mid;
    else if(arr[mid]<num) return binarysearch(arr,mid+1,high,num);
    else return binarysearch(arr,low,mid-1,num);
}
int inter(int *arr,int low,int high,int num){
    if(low>high) return -1;
    int pos=low+(((num-arr[low])*(high-low))/(arr[high]-arr[low]));
    if(arr[pos]==num) return pos;
    else if (arr[pos]<pos) return inter(arr,pos+1,high,num);
    else return inter(arr,low,pos-1,num);
}
int linear(int*arr,int size,int num){
    for(int i=0;i<size;i++){
        if(arr[i]==num) return i;
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int num=7;
    if(binarysearch(arr,0,size-1,num)!=-1){
        printf("\n%d is found in %d position(Binary)\n",num,binarysearch(arr,0,size-1,num));
    }
    else{
        printf("\n%d not found(Binary)\n",num);
    }
    if(inter(arr,0,size-1,num)!=-1){
        printf("\n%d is found in %d position(Interpolation)\n",num,inter(arr,0,size-1,num));
    }
    else{
        printf("\n%d not found(Interpolation)\n",num);
    }
    if(linear(arr,size,num)!=-1){
        printf("\n%d is found in %d position(Linear)\n",num,inter(arr,0,size-1,num));
    }
    else{
        printf("\n%d not found(Linear)\n",num);
    }
}