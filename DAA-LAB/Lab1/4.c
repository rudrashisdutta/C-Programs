#include <stdio.h>
void swap(int *x_rkd_354, int *y_rkd_354)
{
    int temp_rkd_354 = *x_rkd_354;
    *x_rkd_354 = *y_rkd_354;
    *y_rkd_354 = temp_rkd_354;
}
void main()
{
    int a_rkd_354, b_rkd_354, c_rkd_354;
    printf("Enter the numbers:\n");
    scanf("%d%d%d", &a_rkd_354, &b_rkd_354, &c_rkd_354);
    printf("a = %d\nb = %d\nc = %d", a_rkd_354, b_rkd_354, c_rkd_354);
    swap(&a_rkd_354, &b_rkd_354);
    swap(&a_rkd_354, &c_rkd_354);
    printf("\n\nAfter Swapping:\na = %d\nb = %d\nc = %d", a_rkd_354, b_rkd_354, c_rkd_354);
}