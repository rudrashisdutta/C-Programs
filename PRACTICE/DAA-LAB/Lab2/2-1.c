#include <stdio.h>
void gcd(int x_rkd_354, int y_rkd_354)
{
    while (y_rkd_354 > 0)
    {
        int r_rkd_354 = x_rkd_354 % y_rkd_354;
        x_rkd_354 = y_rkd_354;
        y_rkd_354 = r_rkd_354;
    }
    printf("GCD = %d \n", x_rkd_354);
}
void main()
{
    int a_rkd_354, b_rkd_354;
    printf("Enter the first number: ");
    scanf("%d", &a_rkd_354);
    printf("Enter the second number: ");
    scanf("%d", &b_rkd_354);
    gcd(a_rkd_354, b_rkd_354);
}