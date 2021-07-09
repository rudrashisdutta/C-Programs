#include <stdio.h>

void main()
{
    int n_rkd_354, arr_rkd_354[500],count;

    printf("Enter the number of elements of the array (>500):  ");
    scanf("%d", &n_rkd_354);

    printf("Enter the elements of the array: \n");
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        scanf("%d", &arr_rkd_354[i_rkd_354]);
    }
    count = 0;
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        if(arr_rkd_354[i_rkd_354] %2 == 0){
            count++;
            int x_rkd_354 = arr_rkd_354[i_rkd_354];
            int d_rkd_354 = arr_rkd_354[count - 1];
            arr_rkd_354[count - 1] = x_rkd_354;
            arr_rkd_354[i_rkd_354] = d_rkd_354;
        }
    }

    printf("New array:  ");
    for(int i_rkd_354 = 0; i_rkd_354< n_rkd_354; i_rkd_354++){
        printf("%d  ", arr_rkd_354[i_rkd_354]);
    }
}