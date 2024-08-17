#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
// This function is checking if the stack is empty
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// This function is checking if the stack is full
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, char element)
{
    if (isfull(ptr))
    {
        printf("Stack Overflow!!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = element;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("Stack Underflow!!\n");
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return value;
    }
}
int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    else if (a == '{' && b == '}')
    {
        return 1;
    }
    else if (a == '[' && b == ']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int parenthesisMatch(char *exp)
{
    struct stack *sp;
    sp->size = strlen(exp);
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char temp;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isempty(sp))
            {
                return 0;
            }
            else
            {
                temp = pop(sp);
                if (!match(temp, exp[i]))
                    return 0;
            }
        }
    }
    if (isempty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char *exp = "{7-(3-2)+[8+(99-11)]})";

    if (parenthesisMatch(exp))
    {
        printf("Parenthesis are balanced \n");
    }
    else
    {
        printf("Parenthesis are not balanced \n");
    }

    return 0;
}