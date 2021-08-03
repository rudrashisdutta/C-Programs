#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int binarysearch(int a[], int low, int high, int item, int c)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == item)
        {
            c++;
            printf("steps taken by binaru search is %d\n", c);
            return mid;
        }
        else if (item < a[mid])
        {
            c++;
            binarysearch(a, low, mid - 1, item, c);
        }
        else
        {
            c++;
            binarysearch(a, mid + 1, high, item, c);
        }
    }

    else
        return -1;
}

void main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d", &n);
    int arr[100];
    printf("enter the elements : \n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int item;
    printf("enter the element to be searched : ");
    scanf("%d", &item);
    clock_t time;
    time = clock();
    int c = 0;
    int k = binarysearch(arr, 0, n, item, c);
    printf("item found at location %d\n", k + 1);
    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("Total Time = %f\n", time_taken);
}