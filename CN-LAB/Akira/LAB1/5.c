#include <stdio.h>
#include <stdlib.h>
void initArr(int arr[], int m, int n)
{
    for (int i = m; i < n; i++)
    {
        arr[i] = i;
        printf("%d %d", arr[i], i);
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
}
void main()
{
    int *arr;
    arr = (int *)malloc(10);
    initArr(arr, 0, 10);
    printf("\n\nSize 10:  ");
    printArr(arr, 10);
    arr = (int *)realloc(arr, 15);
    initArr(arr, 10, 15);
    printf("\n\nSize 15:  ");
    printArr(arr, 15);
}