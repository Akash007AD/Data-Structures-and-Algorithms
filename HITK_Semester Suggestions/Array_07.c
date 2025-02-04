#include <stdio.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) printf("Array is empty/Array contains one element"); 
    int i = 0; 

    for (int j = 1; j <n; j++) {
        if (arr[j] != arr[i]) { 
            i++;
            arr[i] = arr[j]; 
        }
    }
    
}


int main() {
    int arr[] = {1, 8, 1, 30, 3, 4, 8, 10, 30, 28, 25, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    removeDuplicates(arr,n);
    printArray(arr,n+1);
    

    return 0;
}
