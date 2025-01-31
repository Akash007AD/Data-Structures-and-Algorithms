#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *arr;
    int size;
    int top;
};

struct stack* createstack(int size) {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->arr = (int*)malloc(size * sizeof(int));
    return s;
}

void display(struct stack* s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void push(struct stack* s, int data) {
    if (s->top == s->size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}

int pop(struct stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int temp = s->arr[s->top];
    s->top--;
    return temp;
}

int isEmpty(struct stack* s) {
    return s->top == -1;
}

struct stack* transfer(struct stack* s) {
    struct stack* sortedStack = createstack(s->size);
    struct stack* tempStack = createstack(s->size);

    while (!isEmpty(s)) {
        int temp = pop(s);

        // Move elements from sortedStack to tempStack to find the correct position for temp
        while (!isEmpty(sortedStack) && sortedStack->arr[sortedStack->top] > temp) {
            push(tempStack, pop(sortedStack));
        }

        // Push the current element to the correct position in sortedStack
        push(sortedStack, temp);

        // Move elements back from tempStack to sortedStack
        while (!isEmpty(tempStack)) {
            push(sortedStack, pop(tempStack));
        }
    }

    free(tempStack->arr);
    free(tempStack);
    return sortedStack;
}

int main() {
    struct stack* s = createstack(20);
    
    push(s,13);
    push(s,23);
    push(s,3);
    push(s,53);
    push(s,93);
    push(s,33);
    push(s,113);
    push(s,123);
    push(s,12);
    push(s,24);
    printf("Original Stack: ");
    display(s);

    struct stack* newStack = transfer(s);
    printf("Sorted Stack: ");
    display(newStack);

    // Free allocated memory
    free(s->arr);
    free(s);
    free(newStack->arr);
    free(newStack);

    return 0;
}