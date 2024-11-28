#include <stdio.h>
#include <stdlib.h>

int *queue;
int front = -1, rear = -1, capacity = 0;

void createQueue(int size) {
    queue = (int*)malloc(size * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    capacity = size;
}

int isEmpty() {
    return front == -1;
}

int isFull() {
    return (rear + 1) % capacity == front;
}

void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }
    rear = (rear + 1) % capacity;
    queue[rear] = data;
    if (front == -1) {
        front = 0;
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    do {
        printf("%d ", queue[i]);
        i = (i + 1) % capacity;
    } while (i != (rear + 1) % capacity);
    printf("\n");
}

void freeQueue() {
    free(queue);
}

int main() {
    int size;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    createQueue(size);

    int choice, element;

    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Queue is full\n");
                } else {
                    printf("Enter element to enqueue: ");
                    scanf("%d", &element);
                    enqueue(element);
                }
                break;
            case 2:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    element = dequeue();
                    printf("Dequeued element: %d\n", element);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                freeQueue();
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}