#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;
void create()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("No Space");
        exit(0);
    }
    printf("enter data");
    scanf("%d", temp->data);
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->link = start;
        start = temp;
    }
}

void insert_front()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->link = start;

        start = temp;
    }
}
void insertAtIndex()
{
    int index, i = 0;
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->data);
    printf("\nEnter the index to be inserted:\t");
    scanf("%d", &index);
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (i != index - 1)
        {
            ptr = ptr->link;
            i++;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
}
void insert_rear()
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->data);
    temp->link = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}
void insertAfterNode(struct node *prevNode)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("\nOut of Memory Space:\n");
        return;
    }
    printf("\nEnter the data value for the node:\t");
    scanf("%d", &temp->data);
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        temp->link = prevNode->link;
        prevNode->link = temp;
    }
}
void delete_front()
{
    struct node *temp;
    if (start == NULL)
    {
        printf("\n Empty List:\n");
        return;
    }

    temp = start;
    start = start->link;
    printf("the deleted element is %d", temp->data);
    free(temp);
}

void deleteAtIndex()
{
    struct node *ptr, *temp;
    int index, i = 0;
    if (start == NULL)
    {
        printf("\n Empty List:\n");
        return;
    }
    temp = start;
    ptr = start->link;
    printf("\nEnter the index to be inserted:\t");
    scanf("%d", &index);
    for (i = 0; i < index - 1; i++)
    {
        temp = temp->link;
        ptr = ptr->link;
    }
    temp->link = ptr->link;
    free(ptr);
}
void delete_rear()
{
    struct node *temp, *ptr;
    if (start == NULL)
    {
        printf("\n Empty List:\n");
        return;
    }
    else if (start->link == NULL)
    {
        ptr = start;
        start = NULL;
        printf("deleted :%d", ptr->data);
        free(ptr);
    }
    else
    {
        ptr = start;
        while (ptr->link != NULL)
        {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;
        printf("deleted :%d", ptr->data);
        free(ptr);
    }
}
void deleteValue()
{
    struct node *ptr, *temp;
    int value, i = 0;
    if (start == NULL)
    {
        printf("\n Empty List:\n");
        return;
    }
    temp = start;
    ptr = start->link;
    printf("\nEnter the value to be inserted:\t");
    scanf("%d", &value);
    if (start->data == value)
    {
        ptr = start;
        start = start->link;
        free(ptr);
        return;
    }
    while (ptr->data != value && ptr->link != NULL)
    {
        temp = temp->link;
        ptr = ptr->link;
    }
    if (ptr->data == value)
    {
        temp->link = ptr->link;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    int count = 0;
    ptr = start;
    if (start == NULL)
    {
        printf("\n Empty List:\n");
        return;
    }
    while (ptr->link != NULL)
    {
        printf("%d", ptr->data);
        count = count + 1;
        ptr = ptr->link;
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nMENU \n");
        printf("1.Create 2.Insert_front 3.Insert_rear 4.Delete_front 5.Delete_rear 6.DeleteAtIndex 7.Display 8.Exit\n");

        printf("Enter your choice \t");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_front();
            break;
        case 3:
            insert_rear();
            break;
        case 4:
            delete_front();
            break;
        case 5:
            delete_rear();
            break;
        case 6:
            deleteAtIndex();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\n Wrong Choice:\n");
            break;
        }
    }
    return 0;
}
