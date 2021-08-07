#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int steps = 0;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int random_index(int l, int r)
{
    return (rand() % (r - l)) + l;
}

int partition(int nums[], int l, int h)
{
    int r = random_index(l, h);
    swap(&nums[r], &nums[h]);

    int pivot = nums[h];

    int p = l;

    for (int i = l; i < h; i++)
    {
        if (nums[i] <= pivot)
        {
            swap(&nums[i], &nums[p]);
            p++;
            steps++;
        }
    }
    swap(&nums[p], &nums[h]);

    return p;
}

void QuickSort(int nums[], int l, int h)
{
    if (l < h)
    {
        int j = partition(nums, l, h);
        QuickSort(nums, l, j - 1);
        QuickSort(nums, j + 1, h);
    }
}

void main()
{

    printf("enter size: ");
    int size;
    scanf("%d", &size);
    int *nums = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        scanf("%d",&nums[i]);

    clock_t t = clock();
    QuickSort(nums, 0, size - 1);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Quick sort took %lf seconds to execute \n", time_taken);
    printf("Step Count: %d\n", steps);

    printf("Array after sorting:");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");
}