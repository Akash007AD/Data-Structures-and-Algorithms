#include<stdio.h>
int interpolationsearch(int* arr, int size, int num) {
    int low = 0, high = size - 1, pos;

    while (low <= high && num >= arr[low] && num <= arr[high]) {
        // Prevent division by zero
        if (arr[high] == arr[low]) {
            if (arr[low] == num) return low;
            else return -1;
        }

        // Compute probe position
        pos = low + (((double)(num - arr[low]) / (arr[high] - arr[low])) * (high - low));

        // Bounds check to prevent accessing invalid index
        if (pos < low || pos > high)
            return -1;

        if (arr[pos] == num)
            return pos;
        else if (arr[pos] < num)
            low = pos + 1;
        else
            high = pos - 1;
    }
    
    return -1; // Element not found
}
int main(){
    int arr[]={1,3,5,7,9,11,13,15,17,19};
    int size=sizeof(arr)/sizeof(arr[0]);
    int key=13;
    printf("Position of %d is %d",key,interpolationsearch(arr,size,key));
}