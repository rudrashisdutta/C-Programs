#include <stdio.h>
#include <math.h>
void findnn(int arr[], int n)
{
    int maxCount = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            index = i;
        }
    }
    if (maxCount > n / 2)
        printf(" Yes , element is present");
    else
        printf("No Element Present");
}
int findn(int A[], int n)
{
    int m, i = 0;
    for (int j = 0; j < n; j++)
    {
        if (i == 0)
        {
            m = A[j], i = 1;
        }
        else
        {
            (m == A[j]) ? i++ : i--;
        }
    }
    return m;
}
void main()
{
    int arr[100], n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    printf("Enter the array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    findnn(arr, n);
    if (findn(arr, n) != arr[n - 1])
    {
        printf("\nYes , element is present");
    }
    else
    {
        printf("\nNo Element Present");
    }
}