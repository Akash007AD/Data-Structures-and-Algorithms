#include <stdio.h>

void remove_duplicates(int arr[], int *size) {
    int j = 0;  // Write index

    for (int i = 0; i < *size; i++) {
        int found = 0;  // Flag to check if element is duplicate
        
        // Check if arr[i] already exists in the new array
        for (int k = 0; k < j; k++) {
            if (arr[k] == arr[i]) {
                found = 1;  // Mark as duplicate
                break;
            }
        }

        // If not duplicate, keep the element
        if (!found) {
            arr[j++] = arr[i];
        }
    }

    *size = j;  // Update new size
}

int main() {
    int arr[] = {1, 8, 1, 30, 3, 4, 8, 10, 30, 28, 25, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    remove_duplicates(arr, &size);

    printf("Filtered array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
