#include <stdio.h>
#include <time.h>
void main()
{
    int n_rkd_354;
    printf("Enter size of array:\n");
    scanf("%d", &n_rkd_354);
    int arr[100];
    int i, key, j, step = 0;
    printf("Enter the elements\n");
    for (i = 0; i < n_rkd_354; i++)
    {
        scanf("%d", &arr[i]);
    }
    clock_t time_req = clock();
    for (i = 1; i < n_rkd_354; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            step++;
        }
        arr[j + 1] = key;
    }
    time_req = clock() - time_req;
    printf("Array after insertion sort is:\n");
    for (i = 0; i < n_rkd_354; i++)
    {
        printf("%d, ", arr[i]);
    }

    printf("No of steps are:%d\n", step);
    double total = (double)(time_req) / CLOCKS_PER_SEC;
    printf("Total Execution time: %lf\n", total);
}