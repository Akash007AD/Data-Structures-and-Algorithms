#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
typedef struct Node {
    int val;
    struct Node *next;
} node;

// Function to traverse and display linked list
void linkedListTraversal(node *head) {
    if (head == NULL) {
        printf("Linked list contents: EMPTY\n");
        return;
    }

    printf("Linked list contents: ");
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(", ");
        head = head->next;
    }
    printf("\n");
}

// Insert at beginning
node *insertAtStart(node *head, int data) {
    node *ptr = (node *)malloc(sizeof(node));
    ptr->val = data;
    ptr->next = head;
    return ptr;
}

// Insert at end
node *insertAtEnd(node *head, int data) {
    node *p = head;
    node *q = (node *)malloc(sizeof(node));
    q->val = data;
    q->next = NULL;

    if (head == NULL) {
        return q;
    }

    while (p->next != NULL) {
        p = p->next;
    }
    p->next = q;
    return head;
}

// Insert at a specific position
node *insertAtIndex(node *head, int data, int index) {

    int count = 0;

    node *p = head;
    count=countNodes(head);
    node *new = (node *)malloc(sizeof(node));
    new->val = data;
    if(index<1||index>count+1)
    {
        printf("invalid position\n");
        return;
    }

    if (index == 1) {
        return insertAtStart(head, data);
    }
    if(index=count+1)
    {
        return insertAtEnd(head,data);
    }


    while (count != index-1  && p != NULL) {
        p = p->next;
        count++;
    }

    if (p == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    new->next = p->next;
    p->next = new;
    return head;
}

// Insert after a given node
node *insertAfterNode(node *head, int data, node *indexNode) {
    node *new = (node *)malloc(sizeof(node));
    new->val = data;
    new->next = indexNode->next;
    indexNode->next = new;
    return head;
}

// Insert before a given value
node *insertBeforeValue(node *head, int data, int value) {
    node *p = head;
    node *new;

    if (head == NULL || head->val == value) {
        return insertAtStart(head, data);
    }

    while (p->next != NULL && p->next->val != value) {
        p = p->next;
    }

    if (p->next == NULL) {
        printf("Target element not present!\n");
        return head;
    }

    new = (node *)malloc(sizeof(node));
    new->val = data;
    new->next = p->next;
    p->next = new;
    return head;
}

// Delete the first element
node *deleteFirst(node *head) {
    node *ptr;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Delete the last element
node *deleteEnd(node *head) {
    node *ptr;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    ptr = head;
    if (ptr->next == NULL) {
        free(ptr);
        return NULL;
    }

    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

// Delete element at a specific position
node *deleteAtIndex(node *head, int index) {
    node *p;
    node *ptr;
    int count = 0;

    if (index == 0) {
        return deleteFirst(head);
    }

    p = head;

    while (count != index - 1 && p->next != NULL) {
        p = p->next;
        count++;
    }

    if (p->next == NULL) {
        printf("Invalid position!\n");
        return head;
    }

    ptr = p->next;
    p->next = p->next->next;
    free(ptr);
    return head;
}

// Delete a node by value
node *deleteByValue(node *head, int value) {
    node *p;
    node *ptr;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (head->val == value) {
        return deleteFirst(head);
    }

    p = head;
    while (p->next != NULL && p->next->val != value) {
        p = p->next;
    }

    if (p->next == NULL) {
        printf("Target element not present!\n");
        return head;
    }

    ptr = p->next;
    p->next = p->next->next;
    free(ptr);
    return head;
}

// Reverse the linked list
node *reverseList(node *head) {
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Count the number of nodes in the linked list
int countNodes(node *head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Free all nodes in the linked list
void deallocateList(node *head) {
    node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main menu-driven program
int main() {
    node *head = NULL;
    int choice, data, position, value;
    node *temp;
    int continueCreation = 1;

    // Creation phase
    printf("Creation phase:\n");
    while (continueCreation) {
        printf("Do you want to enter an element (1/0): ");
        scanf("%d", &continueCreation);
        if (continueCreation) {
            printf("Enter element: ");
            scanf("%d", &data);
            head = insertAtEnd(head, data);
        }
    }
    linkedListTraversal(head);

    // Menu-driven interface
    while (1) {
        printf("\nMenu\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Insert after element\n");
        printf("5. Insert before element\n");
        printf("6. Delete first element\n");
        printf("7. Delete last element\n");
        printf("8. Delete at position\n");
        printf("9. Delete given value\n");
        printf("10. Reverse list\n");
        printf("11. Count no of nodes\n");
        printf("12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                head = insertAtStart(head, data);
                linkedListTraversal(head);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                linkedListTraversal(head);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter value: ");
                scanf("%d", &data);
                head = insertAtIndex(head, data, position);
                linkedListTraversal(head);
                break;
            case 4:
                printf("Enter target element: ");
                scanf("%d", &value);
                printf("Enter value: ");
                scanf("%d", &data);
                temp = head;
                while (temp != NULL && temp->val != value) {
                    temp = temp->next;
                }
                if (temp != NULL) {
                    head = insertAfterNode(head, data, temp);
                } else {
                    printf("Target element not present!\n");
                }
                linkedListTraversal(head);
                break;
            case 5:
                printf("Enter target element: ");
                scanf("%d", &value);
                printf("Enter value: ");
                scanf("%d", &data);
                head = insertBeforeValue(head, data, value);
                linkedListTraversal(head);
                break;
            case 6:
                head = deleteFirst(head);
                linkedListTraversal(head);
                break;
            case 7:
                head = deleteEnd(head);
                linkedListTraversal(head);
                break;
            case 8:
                printf("Enter position: ");
                scanf("%d", &position);
                head = deleteAtIndex(head, position);
                linkedListTraversal(head);
                break;
            case 9:
                printf("Enter target value: ");
                scanf("%d", &value);
                head = deleteByValue(head, value);
                linkedListTraversal(head);
                break;
            case 10:
                head = reverseList(head);
                linkedListTraversal(head);
                break;
            case 11:
                printf("No of nodes = %d\n", countNodes(head));
                linkedListTraversal(head);
                break;
            case 12:
                deallocateList(head);
                printf("Deallocating all nodes and exiting program!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
