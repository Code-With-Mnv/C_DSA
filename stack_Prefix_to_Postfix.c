#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

int push(char stack[MAX], char value, int *top);
char pop(char stack[MAX], int *top);
void reverse_list(char list[MAX]);

int main()
{
    char list[MAX];

    printf("Enter the list (string): ");
    scanf("%s", list);

    reverse_list(list);

    printf("Reversed list is: %s\n", list);

    return 0;
}

int push(char stack[MAX], char value, int *top)
{
    if ((*top) == MAX - 1)
    {
        printf("Stack is full\n");
        return -1;
    }
    else
    {
        (*top)++;
        stack[*top] = value;
        return 0;
    }
}

char pop(char stack[MAX], int *top)
{
    if ((*top) == -1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    else
    {
        char x = stack[*top];
        (*top)--;
        return x;
    }
}

void reverse_list(char list[MAX])
{
    char stack[MAX];
    int top = -1, i = 0;

    while (list[i] != '\0')
    {
        push(stack, list[i], &top);
        i++;
    }

    i = 0;
    while (top != -1)
    {
        list[i] = pop(stack, &top);
        i++;
    }
}