#include <stdio.h>
#include <stdlib.h>

void traversal(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", array[i]);
    }
}

void indInsertion(int arr[], int size, int element, int capacity, int index)
{
    if (index > capacity)
    {
        return -1;
    }
    for (int i = size - 1; i <= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
}

void indDeletion(int arr[], int size, int element, int index)
{

    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
