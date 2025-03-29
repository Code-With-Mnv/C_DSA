// Demonstrate the implementation of Queue in C using Arrays

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct QUEUE{
    int queue[MAX_SIZE];
    int head;
    int tail;
}q;

int enqueue(int ele)
{
    if (q.tail == MAX_SIZE)
    {
        printf("Queue full!");
        return 0;
    }

    q.queue[q.tail] = ele;
    q.tail++;
}

int dequeue()
{
    if (q.tail == q.head)
    {
        printf("Queue empty!");
        return 0;
    }

    int dequeued_ele = q.queue[q.head];
    q.head++;
    return dequeued_ele;
}

int display()
{
    if (q.tail == q.head)
    {
        printf("Queue empty!");
        return 0;
    }

    for (int i = q.head; i<q.tail; i++)
    {
        printf("%d ",q.queue[i]);
    }
}

int main(){
    q.head, q.tail = 0;
    int choice;

    do{
        printf("\nChoose a task to perform\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int ele;
            printf("\nEnter the element: ");
            scanf("%d", &ele);
            enqueue(ele);
            printf("\nQueue: ");
            display();
            break;
        case 2:
            printf("\nDequeued element: %d", dequeue());
            printf("\nQueue: ");
            display();
            break;
        case 3:
            printf("\nQueue: ");
            display();
            break;
        case 4:
            printf("Exiting!");
            break;
        default:
            printf("Invalid choice! Try again!");
            break;
        }
    }while(choice != 4);
}
