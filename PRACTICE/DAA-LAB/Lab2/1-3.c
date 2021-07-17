#include <stdio.h>
#include <math.h>
void isPrime(int x_rkd_354)
{
    int d_rkd_354 = 1;
    for (int i_rkd_354 = 2; i_rkd_354 <= sqrt(x_rkd_354); i_rkd_354++)
    {
        if (x_rkd_354 % i_rkd_354 == 0)
        {
            d_rkd_354 = 0;
            break;
        }
    }
    printf("%d is ", x_rkd_354);
    if (d_rkd_354 == 0 || x_rkd_354 == 1)
    {
        printf("not ");
    }
    printf("a prime number.");
}

void main()
{
    int x_rkd_354;
    printf("Enter the number: ");
    scanf("%d", &x_rkd_354);
    isPrime(x_rkd_354);
    return;
}