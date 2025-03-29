
#include <stdio.h>
#include <stdlib.h>

struct ll_node
{

    int data;
    struct ll_node *next;
    struct ll_node *prev;
};

struct ll_node *insert(struct ll_node *list, int value);
struct ll_node *del(struct ll_node *list, int target);

void display(struct ll_node *list);

void main()

{

    struct ll_node *myList;

    int choice, value;

    myList = NULL;

    while (1)
    {

        printf("\nMenu\n");

        printf("1. Insert\n");

        printf("2. Delete\n");

        printf("3. Display \n");

        printf("4. Exit\n");

        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("\nEnter the value to be inserted: ");

            scanf("%d", &value);

            myList = insert(myList, value);

            break;

        case 2:

            printf("\nEnter the value to be deleted: ");

            scanf("%d", &value);

            myList = del(myList, value);

            break;

        case 3:

            display(myList);

            break;

        case 4:
            printf("Exiting from the program!\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}

struct ll_node *insert(struct ll_node *list, int value)

{

    struct ll_node *pnew, *hp, *succ;

    pnew = (struct ll_node *)malloc(sizeof(struct ll_node));

    pnew->data = value;

    pnew->next = NULL;

    pnew->prev = NULL;

    if (list == NULL || list->data > value)

    {

        pnew->next = list;

        if (list != NULL)

            list->prev = pnew;

        list = pnew;

        return list;
    }

    hp = list;

    while (hp->next != NULL && hp->next->data < value)

        hp = hp->next;

    succ = hp->next;

    hp->next = pnew;

    pnew->prev = hp;

    pnew->next = succ;

    if (succ != NULL)

        succ->prev = pnew;

    return list;
}

struct ll_node *del(struct ll_node *list, int target)

{

    struct ll_node *help_ptr, *node2delete;

    help_ptr = list;

    if (help_ptr != NULL)

    {

        if (help_ptr->data == target)

        {

            list = help_ptr->next;

            help_ptr->next->prev = NULL;

            free(help_ptr);

            return list;
        }

        while (help_ptr->next != NULL)

        {

            if (help_ptr->next->data == target)

            {

                node2delete = help_ptr->next;

                help_ptr->next = node2delete->next;

                if (node2delete->next != NULL)

                    node2delete->next->prev = help_ptr;

                free(node2delete);

                return list;
            }

            help_ptr = help_ptr->next;
        }

        printf("Element not found");

        return list;
    }

    printf("List empty");

    return list;
}

void display(struct ll_node *list)

{

    struct ll_node *hp;

    hp = list;

    printf("\n");

    while (hp != NULL)

    {

        printf("%d->", hp->data);

        hp = hp->next;
    }
}
Menu 1. Insert 2. Delete 3. Display 4. Exit
    Enter your choice : 1

    Enter the value to be inserted : 5

    Menu 1. Insert 2. Delete 3. Display 4. Exit
        Enter your choice : 1

    Enter the value to be inserted : 9

    Menu 1. Insert 2. Delete 3. Display 4. Exit
        Enter your choice : 1

    Enter the value to be inserted : 6

    Menu 1. Insert 2. Delete 3. Display 4. Exit
        Enter your choice : 1

    Enter the value to be inserted : 8

    Menu 1. Insert 2. Delete 3. Display 4. Exit
        Enter your choice : 3

    5->6->8->9->Menu 1. Insert 2. Delete 3. Display 4. Exit
        Enter your choice : 2

    Enter the value to be deleted : 3 Element not found
        Menu 1. Insert 2. Delete 3. Display 4. Exit
            Enter your choice : 2

    Enter the value to be deleted : 8

    Menu 1. Insert 2. Delete 3. Display 4. Exit
        Enter your choice : 3

    5->6->9->Menu 1. Insert 2. Delete 3. Display 4. Exit
        Enter your choice : 4 Exiting from the program !
