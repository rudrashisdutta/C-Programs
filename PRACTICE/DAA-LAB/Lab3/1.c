#include <stdio.h>
#include <time.h>
void main()
{
    time_t start, end;
    start = time(NULL);
    //Here we will type the code
    int n; // size
    printf("Enter size");
    scanf("%d", &n);
    int a[100];
    int key = 0;
    int j = 0;
    int c = 0;
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
            c++;
        }
        a[j + 1] = key;
    }
    printf("Sorted Array: \n ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    end = time(NULL);
    printf("\n Time taken to print sum is %.2f seconds", difftime(end, start));
    printf("\n Loop ran in step count = %d", c);
}