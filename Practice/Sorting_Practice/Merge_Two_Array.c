#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
int* merge_array(int *arr, int arr_size, int* brr, int brr_size) {
    int* crr = (int*)malloc((arr_size + brr_size) * sizeof(int));
    if (crr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    int i = 0, j = 0, k = 0;

    // Merging process
    while (i < arr_size && j < brr_size) {
        if (arr[i] < brr[j]) {
            crr[k++] = arr[i++];
        } else {
            crr[k++] = brr[j++];
        }
    }

    // Copy remaining elements from arr[]
    while (i < arr_size) {
        crr[k++] = arr[i++];
    }

    // Copy remaining elements from brr[]
    while (j < brr_size) {
        crr[k++] = brr[j++];
    }

    return crr;
}

int main() {
    int arr[] = {1, 3, 5, 7};
    int brr[] = {2, 4, 6, 8, 10};

    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int brr_size = sizeof(brr) / sizeof(brr[0]);

    int merged_size = arr_size + brr_size;
    
    // Use a pointer to store dynamically allocated merged array
    int* merged_array = merge_array(arr, arr_size, brr, brr_size);

    printf("Merged Array: ");
    for (int i = 0; i < merged_size; i++) {
        printf("%d ", merged_array[i]);
    }
    printf("\n");

    // Free dynamically allocated memory
    free(merged_array);
    
    return 0;
}
