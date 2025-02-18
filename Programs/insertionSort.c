#include <stdio.h>
#include <stdlib.h>

void insertionSort(int Array[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int key = Array[i];
        int j = i - 1;
        while (j >= 0 && key < Array[j])
        {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
    }
}