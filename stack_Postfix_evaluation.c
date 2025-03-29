#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 10

struct STACK
{
    int stack[MAX_SIZE];
    int top;
} s;

int push(int num)
{
    if (s.top == MAX_SIZE - 1)
    {
        printf("Stack overflow!\n");
        return 0;
    }

    s.stack[s.top] = num;
    s.top++;
    return 1;
}

int pop()
{
    if (s.top == 0)
    {
        printf("Stack underflow!\n");
        return 0;
    }

    s.top--;
    int popped_item = s.stack[s.top];
    return popped_item;
}

int main()
{
    s.top = 0;
    char post_Str[MAX_SIZE];

    printf("Enter the postfix string: ");
    scanf("%s", post_Str);

    for (int i = 0; i < strlen(post_Str); i++)
    {
        char charr = post_Str[i];

        if (isdigit(charr))
        {
            int num = charr - '0';
            push(num);
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();
            char operatorr = charr;

            switch (operatorr)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            default:
                printf("Invalid operator: %c\n", operatorr);
                return 1;
            }
        }
    }
    printf("\nFinal value: %d\n", pop());
    return 0;
}
