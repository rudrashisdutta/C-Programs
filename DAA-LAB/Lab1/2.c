#include <stdio.h>
void main()
{
    int n_rkd_354, duplicate_rkd_354, arr_rkd_354[500], largestD_rkd_354[2], duplicateE_rkd_354[500];

    printf("Enter the number of elements of the array (>500):  ");
    scanf("%d", &n_rkd_354);

    printf("Enter the elements of the array (Make sure to enter a few duplicate ones): \n");
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        scanf("%d", &arr_rkd_354[i_rkd_354]);
    }
    largestD_rkd_354[0] = 0;
    largestD_rkd_354[1] = 0;
    duplicate_rkd_354 = 0;
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {

        int flag = 1;
        for (int x_rkd_354 = 0; x_rkd_354 < duplicate_rkd_354; x_rkd_354++)
        {
            if (arr_rkd_354[i_rkd_354] == duplicateE_rkd_354[x_rkd_354])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            int noa_rkd_354 = 0;
            for (int j_rkd_354 = 0; j_rkd_354 < n_rkd_354; j_rkd_354++)
            {
                if (arr_rkd_354[i_rkd_354] == arr_rkd_354[j_rkd_354])
                    noa_rkd_354++;
            }
            if (noa_rkd_354 > 1)
            {
                if (largestD_rkd_354[0] < noa_rkd_354)
                {
                    largestD_rkd_354[0] = noa_rkd_354;
                    largestD_rkd_354[1] = arr_rkd_354[i_rkd_354];
                }
                duplicateE_rkd_354[duplicate_rkd_354] = arr_rkd_354[i_rkd_354];
                duplicate_rkd_354++;
            }
        }
    }
    printf("Number of duplicate elements:  %d\nElement with largest number of occurances:  %d  - %d occurances", duplicate_rkd_354, largestD_rkd_354[1], largestD_rkd_354[0]);
}