#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int top = -1;
int stack[MAX_SIZE];

void push();
void pop();
void display();
void isEmpty();
void isFull();
void main()
{
    int choice = 0;
    while (choice != 6)
    {
        printf("enter the operation to be performed\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Display\n");
        printf("4.Isempty\n");
        printf("5.Isfull\n");
        printf("6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
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
            exit(0);
        default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
}
void push()
{
    int x;
    printf("\nEnter the value to be pushed: ");
    scanf("%d", &x);
    if (top == MAX_SIZE - 1)
    {
        printf("\nStack Overflowed");
    }
    else
    {
        top = top + 1;
        stack[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nStack Underflowed");
    }
    else
    {
        top = top - 1;
    }
}
void display()
{
    int i;
    printf("\nThe Stack is \n");
    for (i = 0; i <= top; i++)
    {
        printf("%d", stack[i]);
        printf("\t");
    }
    printf("\n");
}
void isEmpty()
{
    if (top == -1)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("\nStack is not empty\n");
    }
}
void isFull()
{
    if (top == MAX_SIZE - 1)
    {
        printf("\n Stack is full\n");
    }
    else
    {
        printf("\nStack is not full\n");
    }
}
