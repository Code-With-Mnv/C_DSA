#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    int ele;
    printf("Enter the element to push: ");
    scanf("%d", &ele);

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = ele;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("%d popped\n", temp->data);
    top = top->next;
    free(temp);
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    struct node *curr = top;
    printf("Stack elements: ");
    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    int choice;
    printf("Stack Implementation using Linked List\n");

    do
    {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push();
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
