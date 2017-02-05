#include <stdio.h>
#include <stdlib.h>

/*
    Jeremy Quade
    1/12/17
    Basic Queue with pointers and structs using integers as inputs
*/

struct queueNode
{
    int number;
    struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int number);
void menu();

int main()
{
    QueueNodePtr headPtr = NULL;
    QueueNodePtr tailPtr = NULL;
    int number;
    int choice = 0;

    while(choice != 4)
    {
        menu();
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Please enter a number to enqueue: ");
                scanf("%d", &number);
                enqueue(&headPtr, &tailPtr, number);
                printQueue(headPtr);
                printf("\n");
                break;

            case 2:
                printf("Dequeued: %d\n\n", dequeue(&headPtr, &tailPtr));
                printQueue(headPtr);
                break;

            case 3:
                printQueue(headPtr);
                printf("\n");
                break;

            case 4:
                break;

            default:
                printf("Incorrect entry, please enter another entry\n\n");
                break;
        }

    }
    return 0;
}

void printQueue(QueueNodePtr currentPtr)
{
    if(currentPtr == NULL)
    {
        printf("The Queue is empty.\n\n");
    }

    else
    {
        printf("The Queue: ");
        while(currentPtr != NULL)
        {
            printf("%d", currentPtr->number);
            printf(" --> ");
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL");
        printf("\n\n");
    }
}

int isEmpty(QueueNodePtr headPtr)
{
    if(headPtr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
    int value;
    if(isEmpty(*headPtr))
    {
        value = -1;
        printf("Queue is already empty\n");
    }

    else if(isEmpty((*headPtr)->nextPtr))
    {
        value = (*headPtr)->number;
        *headPtr = NULL;
        *tailPtr = NULL;
    }

    else if(!isEmpty((*headPtr)->nextPtr))
    {
        value = (*headPtr)->number;
        *headPtr = (*headPtr)->nextPtr;
    }
    return value;
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int number)
{
    QueueNodePtr newPtr = malloc(sizeof(QueueNode));

    newPtr->number = number;
    newPtr->nextPtr = NULL;

    if(isEmpty(*headPtr))
    {
        *headPtr = newPtr;
    }

    else
    {
        (*tailPtr)->nextPtr = newPtr;
    }

    *tailPtr = newPtr;
}

void menu()
{
    printf("1. Enqueue a number\n");
    printf("2. Dequeue a number\n");
    printf("3. Print queue\n");
    printf("4. Exit\n\n");

    printf("Enter a choice: ");
}
