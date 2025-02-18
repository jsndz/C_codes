#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void array2d();
void printsparse(int[][3]);
void readsparse(int[][3]);
void transpose(int[][3], int[][3]);
int main()
{
    int a[MAX][3], b[MAX][3], m, n;
    printf("1. Demonstrate the working of dynamic memory allocation of 2D array\n");
    array2d();
    printf("\n2. Demonstrate Sparse Matrix Transpose\n");
    printf("\nRead Operation: Enter the size of matrix (rows,columns):\n");
    scanf("%d%d", &m, &n);
    a[0][0] = m;
    a[0][1] = n;
    readsparse(a);
    printf("Transpose the matrix\n");
    transpose(a, b);
    printsparse(b);
}
void array2d()
{
    int **ptr, i, j;
    int r, c;
    printf("Enter Row & Column Dimension\n");
    scanf("%d%d", &r, &c);
    ptr = (int **)malloc(r * sizeof(int *));
    for (i = 0; i < r; i++)

        ptr[i] = (int *)malloc(c * sizeof(int));
    printf("Read values into array\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &ptr[i][j]);
    printf("Array Elements are:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d\t", ptr[i][j]);
        }
        printf("\n");
    }
}
void readsparse(int a[MAX][3])
{
    int i, t;
    printf("\nEnter no. of non-zero elements:");
    scanf("%d", &t);
    a[0][2] = t;
    for (i = 1; i <= t; i++)
    {
        printf("\nEnter the next triple(row,column,value):");
        scanf("%d%d%d\n", &a[i][0], &a[i][1], &a[i][2]);
    }
}
void printsparse(int b[MAX][3])
{
    int i, n;
    n = b[0][2]; // no of 3-triples
    printf("\nAfter Transpose:\n");
    printf("\nrow\t\tcolumn\t\tvalue\n");
    for (i = 0; i <= n; i++)

        printf("%d\t\t%d\t\t%d\n", b[i][0], b[i][1], b[i][2]);
}
void transpose(int a[][3], int b[][3])
{
    int i, j, k, n;
    int rowterms[MAX], startingpos[MAX];
    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];
    k = a[0][1]; // No of Column
    n = a[0][2]; // No of terms
    for (i = 0; i < k; i++)
        rowterms[i] = 0;
    for (i = 1; i <= n; i++)
        rowterms[a[i][1]]++;
    startingpos[0] = 1;
    for (i = 1; i < k; i++)
        startingpos[i] = startingpos[i - 1] + rowterms[i - 1];
    for (i = 1; i <= n; i++)
    {
        j = startingpos[a[i][1]]++;
        b[j][0] = a[i][1];
        b[j][1] = a[i][0];
        b[j][2] = a[i][2];
    }
}