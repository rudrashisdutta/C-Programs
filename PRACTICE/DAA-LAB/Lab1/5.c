#include <stdio.h>

int countNonZeroes(int arr_rkd_354[100][100], int n_rkd_354)
{
    int numOfNonZeroes_rkd_354 = 0;
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        for (int j_rkd_354 = 0; j_rkd_354 < n_rkd_354; j_rkd_354++)
        {
            if (arr_rkd_354[i_rkd_354][j_rkd_354] != 0)
                numOfNonZeroes_rkd_354++;
        }
    }
    return numOfNonZeroes_rkd_354;
}
int productOfDiagonal(int arr_rkd_354[100][100], int n_rkd_354)
{
    int mult_rkd_354 = 1;
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        for (int j_rkd_354 = 0; j_rkd_354 < n_rkd_354; j_rkd_354++)
        {
            if (i_rkd_354 == j_rkd_354 || (i_rkd_354 + j_rkd_354) == (n_rkd_354 - 1))
            {
                mult_rkd_354 *= arr_rkd_354[i_rkd_354][j_rkd_354];
            }
        }
    }
    return mult_rkd_354;
}
int sumOfElemAboveLeadDiag(int arr_rkd_354[100][100], int n_rkd_354)
{
    int sumOfElem_rkd_354 = 0;
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        for (int j_rkd_354 = 0; j_rkd_354 < n_rkd_354; j_rkd_354++)
        {
            if (j_rkd_354>i_rkd_354){
                sumOfElem_rkd_354 += arr_rkd_354[i_rkd_354][j_rkd_354];
                
            }
        }
    }
    return sumOfElem_rkd_354;
}
void printElemBelowMinorDiag(int arr_rkd_354[100][100], int n_rkd_354)
{
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        for (int j_rkd_354 = 0; j_rkd_354 < n_rkd_354; j_rkd_354++)
        {
            if ((i_rkd_354 + j_rkd_354) > (n_rkd_354 - 1)){
                printf("%d\t",arr_rkd_354[i_rkd_354][j_rkd_354]);
            } else{
                printf("x\t");
            }
        }
        printf("\n");
    }
}
void main()
{
    int arr_rkd_354[100][100], n_rkd_354;
    printf("Enter the value of n:  ");
    scanf("%d", &n_rkd_354);

    printf("Enter the elements of the matrix:\n");
    for (int i_rkd_354 = 0; i_rkd_354 < n_rkd_354; i_rkd_354++)
    {
        for (int j_rkd_354 = 0; j_rkd_354 < n_rkd_354; j_rkd_354++)
        {
            scanf("%d", &arr_rkd_354[i_rkd_354][j_rkd_354]);
        }
    }
    printf("Number of Non Zero elements:  %d", countNonZeroes(arr_rkd_354, n_rkd_354));
    printf("\nProduct of Diagonal:  %d", productOfDiagonal(arr_rkd_354, n_rkd_354));
    printf("\nSum of the elements above the leading diagonal:  %d\n", sumOfElemAboveLeadDiag(arr_rkd_354, n_rkd_354));
    printElemBelowMinorDiag(arr_rkd_354,n_rkd_354);
}