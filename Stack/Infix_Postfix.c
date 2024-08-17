#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

// Stack structure for characters (for infix to postfix conversion)
typedef struct {
    int top;
    char items[MAX];
} CharStack;

// Stack structure for integers (for postfix evaluation)
typedef struct {
    int top;
    int items[MAX];
} IntStack;

void initCharStack(CharStack *stack) {
    stack->top = -1;
}

int isCharStackEmpty(CharStack *stack) {
    return stack->top == -1;
}

int isCharStackFull(CharStack *stack) {
    return stack->top == MAX - 1;
}

void pushChar(CharStack *stack, char item) {
    if (isCharStackFull(stack)) {
        printf("Char stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

char popChar(CharStack *stack) {
    if (isCharStackEmpty(stack)) {
        printf("Char stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

char peekChar(CharStack *stack) {
    if (isCharStackEmpty(stack)) {
        printf("Char stack is empty\n");
        exit(1);
    }
    return stack->items[stack->top];
}

void initIntStack(IntStack *stack) {
    stack->top = -1;
}

int isIntStackEmpty(IntStack *stack) {
    return stack->top == -1;
}

int isIntStackFull(IntStack *stack) {
    return stack->top == MAX - 1;
}

void pushInt(IntStack *stack, int item) {
    if (isIntStackFull(stack)) {
        printf("Int stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = item;
}

int popInt(IntStack *stack) {
    if (isIntStackEmpty(stack)) {
        printf("Int stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

int peekInt(IntStack *stack) {
    if (isIntStackEmpty(stack)) {
        printf("Int stack is empty\n");
        exit(1);
    }
    return stack->items[stack->top];
}

int precedence(char op) {
    switch (op) {
        case '^': return 4;
        case '*': case '/': return 3;
        case '+': case '-': return 2;
        default: return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

char* infixToPostfix(const char* infix) {
    CharStack opStack;
    initCharStack(&opStack);
    int len = strlen(infix);
    char* postfix = (char*)malloc((len + 1) * sizeof(char));
    int j = 0;

    for (int i = 0; i < len; i++) {
        if (isdigit(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            pushChar(&opStack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isCharStackEmpty(&opStack) && peekChar(&opStack) != '(') {
                postfix[j++] = popChar(&opStack);
            }
            popChar(&opStack); // Remove '('
        } else if (isOperator(infix[i])) {
            while (!isCharStackEmpty(&opStack) && precedence(peekChar(&opStack)) >= precedence(infix[i])) {
                postfix[j++] = popChar(&opStack);
            }
            pushChar(&opStack, infix[i]);
        }
    }

    while (!isCharStackEmpty(&opStack)) {
        postfix[j++] = popChar(&opStack);
    }

    postfix[j] = '\0';
    return postfix;
}

int evaluatePostfix(const char* postfix) {
    IntStack numStack;
    initIntStack(&numStack);
    int len = strlen(postfix);

    for (int i = 0; i < len; i++) {
        if (isdigit(postfix[i])) {
            pushInt(&numStack, postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            int val2 = popInt(&numStack);
            int val1 = popInt(&numStack);
            int result;

            switch (postfix[i]) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    result = val1 / val2; 
                    break;
                case '^': result = (int)pow(val1, val2); break;
                default:
                    printf("Invalid operator %c\n", postfix[i]);
                    exit(1);
            }
            pushInt(&numStack, result);
        }
    }

    return popInt(&numStack);
}

int main() {
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    char* postfix = infixToPostfix(infix);
    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of the expression: %d\n", result);

    free(postfix); // Free postfix memory
    return 0;
}
