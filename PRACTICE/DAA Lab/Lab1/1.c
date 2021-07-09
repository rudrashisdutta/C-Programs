#include <stdio.h>
void main()
{
    int n_rkd_354, arr_rkd_354[500];

    printf("Enter the number of elements of the array (>500):  ");
    scanf("%d", &n_rkd_354);

    printf("Enter the elements of the array: \n");
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        scanf("%d", &arr_rkd_354[i_rkd_354]);
    }

    int smallest_rkd_354 = arr_rkd_354[0];
    for (int i_rkd_354 = 1; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        if (arr_rkd_354[i_rkd_354] < smallest_rkd_354)
            smallest_rkd_354 = arr_rkd_354[i_rkd_354];
    }
    int largest_rkd_354 = arr_rkd_354[0];
    for (int i_rkd_354 = 1; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        if (arr_rkd_354[i_rkd_354] > largest_rkd_354)
            largest_rkd_354 = arr_rkd_354[i_rkd_354];
    }

    printf("Smallest:  %d\nLargest:  %d", smallest_rkd_354, largest_rkd_354);
}