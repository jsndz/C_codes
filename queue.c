#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int rear = -1;
int front = -1;
int queue[MAX_SIZE];
void enqueue();
void dequeue();
void peek();
void display();
void isEmpty();
void isFull();

void main()
{
    int choice = 0;
    while (choice != 7)
    {
        printf("enter the operation to be performed\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Isempty\n");
        printf("5.Isfull\n");
        printf("6.Peek\n");
        printf("7.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            peek();
            break;
        case 7:
            exit(0);
        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
}
void enqueue()
{
    int x;
    printf("\nEnter the value to be enqueued: ");
    scanf("%d", &x);
    if (rear == MAX_SIZE - 1)
    {
        printf("\nQueue Overflowed");
    }
    else
    {
        if (front = -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = x;
    }
}
void display()
{
    int i;
    printf("\nThe Stack is \n");
    for (i = front; i <= rear; i++)
    {
        printf("%d", queue[i]);
        printf("\t");
    }
    printf("\n");
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue Underflowed");
    }
    else
    {
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}
void peek()
{
    if (rear == -1)
    {
        printf("\nQueue is Underflowed\n");
    }
    else
    {
        printf("\n%d\n", queue[rear]);
    }
}

void isEmpty()
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue is not empty\n");
    }
}
void isFull()
{
    if (rear == MAX_SIZE - 1)
    {
        printf("\n Queue is full\n");
    }
    else
    {
        printf("\nQueue is not full\n");
    }
}