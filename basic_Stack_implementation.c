// Demonstrate the basic implementation of array as a stack

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct STACK
{
    int stack[MAX_SIZE];
    int top;
} s;

int push(int num)
{
    if (s.top == MAX_SIZE-1){
        printf("Stack overflow!\n");
        return 0;
    }

    s.stack[s.top] = num;
    s.top++;
}

int pop(){
    if (s.top == 0){
        printf("Stack underflow!\n");
        return 0;
    }

    s.top--;
    int popped_item = s.stack[s.top];
    printf("Popped item: %d\n", popped_item);
}

int display(){
    if (s.top == 0){
        printf("Stack underflow!\n");
        return 0;
    }

    for (int i = 0; i < s.top;i++){
        printf("%d",s.stack[i]);
    }
    printf("\n");
}

void main()
{
    s.top = 0;
    int choice;
    do
    {
        printf("\nChoose the method to implement: \n");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int num;
            printf("\nEnter the number to be pushed: ");
            scanf("%d", &num);
            push(num);
            display();
            break;
        case 2:
            printf("\nPopping the top element.\n");
            pop();
            display();
            break;
        case 3:
            printf("\nThe stack is: ");
            display();
            break;
        case 4:
            printf("\nExiting!");
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 4);
}
