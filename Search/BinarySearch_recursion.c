#include <stdio.h>
#include <stdlib.h>
int binary_search(int *arr, int low, int high, int key)
{
    if(low>high) return -1;
    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] < key)
    {

        return binary_search(arr, low + 1, high, key);
    }
    else 
    {

        return binary_search(arr, low, high - 1, key);
    }
    

}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = (sizeof(arr) / sizeof(arr[0]));
    int low = 0;
    int high = size - 1;
    int key;
    printf("Enter your key: ");
    scanf("%d",&key);
    int result= binary_search(arr, low, high, key);
    if (result!=-1){
        printf("Element %d is found in %d position",key,result);
    }
    else{
        printf("Element %d not found",key);
    }

}