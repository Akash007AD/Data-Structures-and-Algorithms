#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int front, rear, size, capacity;
} Queue;

// Function to create a queue with a given initial capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

// Function to resize the queue when full
void resizeQueue(Queue* queue) {
    queue->capacity *= 2;
    queue->data = (int*)realloc(queue->data, queue->capacity * sizeof(int));
}

// Function to insert an element into the queue
void insert(Queue* queue, int value) {
    if (isFull(queue)) {
        resizeQueue(queue);
        printf("Queue is full, resizing...\n");
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
    queue->size++;
    printf("Inserted %d into the queue.\n", value);
}

// Function to delete an element from the queue
void delete(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty! Cannot delete.\n");
        return;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    printf("Deleted %d from the queue.\n", value);
}

// Function to display the elements in the queue
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    for (int i = 0; i < queue->size; i++) {
        int index = (queue->front + i) % queue->capacity;
        printf("%d ", queue->data[index]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice, value;
    Queue* queue = createQueue(2); // Initial capacity of 2

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(queue, value);
                break;
            case 2:
                delete(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                free(queue->data); // Free the dynamically allocated memory
                free(queue);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
