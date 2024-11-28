#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Utility functions
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void displayList(struct Node* head) {
    while (head) {
        printf("%d%s", head->data, head->next ? " -> " : " -> NULL\n");
        head = head->next;
    }
}

int countNodes(struct Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Linked list creation function
void createLinkedList(struct Node** head) {
    int n, data;
    printf("Enter the number of elements you want to insert in the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}

// Insertion functions
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (!(*head)) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

void insertAtPosition(struct Node** head, int data, int position) {
    int totalNodes = countNodes(*head);
    if (position < 1 || position > totalNodes + 1) {
        printf("Position out of bounds\n");
        return;
    }

    if (position == 1) {
        insertAtBeginning(head, data);
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp; i++) temp = temp->next;
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void insertAfterElement(struct Node** head, int data, int afterValue) {
    struct Node* temp = *head;
    while (temp && temp->data != afterValue) temp = temp->next;
    if (temp) {
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Element not found\n");
    }
}

void insertBeforeElement(struct Node** head, int data, int beforeValue) {
    if (!(*head) || (*head)->data == beforeValue) {
        insertAtBeginning(head, data);
    } else {
        struct Node* temp = *head;
        while (temp->next && temp->next->data != beforeValue) temp = temp->next;
        if (temp->next) {
            struct Node* newNode = createNode(data);
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            printf("Element not found\n");
        }
    }
}

// Deletion functions
void deleteFirstNode(struct Node** head) {
    if (*head) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        printf("List is empty\n");
    }
}

void deleteLastNode(struct Node** head) {
    if (*head) {
        struct Node* temp = *head;
        if (!temp->next) {
            free(temp);
            *head = NULL;
        } else {
            while (temp->next->next) temp = temp->next;
            free(temp->next);
            temp->next = NULL;
        }
    } else {
        printf("List is empty\n");
    }
}

void deleteNodeAtPosition(struct Node** head, int position) {
    int totalNodes = countNodes(*head);
    if (position < 1 || position > totalNodes) {
        printf("Position out of bounds\n");
        return;
    }

    if (position == 1) {
        deleteFirstNode(head);
    } else {
        struct Node* temp = *head;
        for (int i = 1; i < position - 1 && temp; i++) temp = temp->next;
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

void deleteNodeByValue(struct Node** head, int value) {
    if (*head) {
        if ((*head)->data == value) {
            deleteFirstNode(head);
        } else {
            struct Node* temp = *head;
            while (temp->next && temp->next->data != value) temp = temp->next;
            if (temp->next) {
                struct Node* toDelete = temp->next;
                temp->next = temp->next->next;
                free(toDelete);
            } else {
                printf("Element not found\n");
            }
        }
    } else {
        printf("List is empty\n");
    }
}

// Reverse the list
void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    struct Node* head = NULL;

    int choice, value, position, refValue;
    char createChoice;

    printf("Do you want to create a linked list? (y/n): ");
    scanf(" %c", &createChoice);

    if (createChoice == 'y' || createChoice == 'Y') {
        createLinkedList(&head);
        printf("Linked list created.\n");
        displayList(head);
    }
    printf("\nMenu\n1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Insert after element\n5. Insert before element\n6. Delete first element\n7. Delete last element\n8. Delete at position\n9. Delete given value\n10. Reverse list\n11. Count no of nodes\n12. Exit");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d%d", &value, &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                printf("Enter value and after which element: ");
                scanf("%d%d", &value, &refValue);
                insertAfterElement(&head, value, refValue);
                break;
            case 5:
                printf("Enter value and before which element: ");
                scanf("%d%d", &value, &refValue);
                insertBeforeElement(&head, value, refValue);
                break;
            case 6:
                deleteFirstNode(&head);
                break;
            case 7:
                deleteLastNode(&head);
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteNodeAtPosition(&head, position);
                break;
            case 9:
                printf("Enter value: ");
                scanf("%d", &value);
                deleteNodeByValue(&head, value);
                break;
            case 10:
                reverseList(&head);
                break;
            case 11:
                printf("No of nodes = %d\n", countNodes(head));
                printf("Linked list contents: ");
                displayList(head);
                break;
            case 12:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
        displayList(head);
    }
    
    return 0;
}