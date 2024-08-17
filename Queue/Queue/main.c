#include <stdio.h>
#include <stdlib.h>

typedef struct Deque {
    int *data;
    int front, rear, size, capacity;
} Deque;

// Function to create a deque with a given initial capacity
Deque* createDeque(int capacity) {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->capacity = capacity;
    deque->front = -1;
    deque->rear = 0;
    deque->size = 0;
    deque->data = (int*)malloc(deque->capacity * sizeof(int));
    return deque;
}

// Function to check if the deque is full
int isFull(Deque* deque) {
    return (deque->size == deque->capacity);
}

// Function to check if the deque is empty
int isEmpty(Deque* deque) {
    return (deque->size == 0);
}

// Function to resize the deque when full
void resizeDeque(Deque* deque) {
    if (deque->capacity >= 100) {
        printf("Cannot resize beyond the capacity of 100.\n");
        return;
    }

    int new_capacity = deque->capacity * 2;
    if (new_capacity > 100) {
        new_capacity = 100; // Cap the capacity at 100
    }

    int* new_data = (int*)malloc(new_capacity * sizeof(int));

    // Rearrange elements in the new array
    int i = deque->front;
    int j = 0;
    while (1) {
        new_data[j++] = deque->data[i];
        if (i == deque->rear) break;
        i = (i + 1) % deque->capacity;
    }

    free(deque->data);
    deque->data = new_data;
    deque->front = 0;
    deque->rear = deque->size - 1;
    deque->capacity = new_capacity;

    printf("Resized deque to capacity %d.\n", deque->capacity);
}

// Function to insert an element at the front
void insertFront(Deque* deque, int value) {
    if (isFull(deque)) {
        resizeDeque(deque);
        if (isFull(deque)) { // After resizing, check again if it's still full
            printf("Deque is full, cannot insert %d.\n", value);
            return;
        }
    }
    if (deque->front == -1) { // First element insertion
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = deque->capacity - 1;
    } else {
        deque->front--;
    }
    deque->data[deque->front] = value;
    deque->size++;
    printf("Inserted %d at the front.\n", value);
}

// Function to insert an element at the rear
void insertRear(Deque* deque, int value) {
    if (isFull(deque)) {
        resizeDeque(deque);
        if (isFull(deque)) { // After resizing, check again if it's still full
            printf("Deque is full, cannot insert %d.\n", value);
            return;
        }
    }
    if (deque->front == -1) { // First element insertion
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == deque->capacity - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->data[deque->rear] = value;
    deque->size++;
    printf("Inserted %d at the rear.\n", value);
}

// Function to delete an element from the front
void deleteFront(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty! Cannot delete.\n");
        return;
    }
    int value = deque->data[deque->front];
    if (deque->front == deque->rear) { // Only one element was present
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == deque->capacity - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
    deque->size--;
    printf("Deleted %d from the front.\n", value);
}

// Function to delete an element from the rear
void deleteRear(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty! Cannot delete.\n");
        return;
    }
    int value = deque->data[deque->rear];
    if (deque->front == deque->rear) { // Only one element was present
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = deque->capacity - 1;
    } else {
        deque->rear--;
    }
    deque->size--;
    printf("Deleted %d from the rear.\n", value);
}

// Function to display the elements in the deque
void display(Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque elements are: ");
    int i = deque->front;
    while (1) {
        printf("%d ", deque->data[i]);
        if (i == deque->rear)
            break;
        i = (i + 1) % deque->capacity;
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;
    Deque* deque = createDeque(2); // Initial capacity of 2

    while (1) {
        printf("\nDeque Operations:\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at the front: ");
                scanf("%d", &value);
                insertFront(deque, value);
                break;
            case 2:
                printf("Enter value to insert at the rear: ");
                scanf("%d", &value);
                insertRear(deque, value);
                break;
            case 3:
                deleteFront(deque);
                break;
            case 4:
                deleteRear(deque);
                break;
            case 5:
                display(deque);
                break;
            case 6:
                printf("Exiting...\n");
                free(deque->data); // Free the dynamically allocated memory
                free(deque);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
