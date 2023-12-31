#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5

int front = -1, rear = -1;
int queue[MAXSIZE];

void enqueue(int x)
{

    if ((rear + 1) % MAXSIZE == front)
    {
        printf("queue is full");
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAXSIZE;
        }
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty");
    }
    else
    {
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAXSIZE;
        }
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty");
    }
    else
    {
        for (int i = front; i <= rear; i = (rear + 1) % MAXSIZE)
        {
            printf("%d", queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice;
    while (1)
    {
        printf("Enter the choice\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int x;
            printf("Enter the value to be enqueued\n");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}
