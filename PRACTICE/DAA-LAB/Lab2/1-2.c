#include <stdio.h>
int isPrime(int n_rkd_354, int i_rkd_354)
{
    if (n_rkd_354 == 1)
        return 0;
    if (i_rkd_354 == 1)
    {
        return 1;
    }
    else
    {
        if (n_rkd_354 % i_rkd_354 == 0)
        {
            return 0;
        }
        else
        {
            return isPrime(n_rkd_354, i_rkd_354 - 1);
        }
    }
}
void main()
{
    int n_rkd_354;
    printf("Enter the number:  ");
    scanf("%d", &n_rkd_354);
    int i_rkd_354 = n_rkd_354 / 2;
    if (isPrime(n_rkd_354, i_rkd_354) == 1)
    {
        printf("%d is prime number", n_rkd_354);
    }
    else
    {
        printf("%d is not prime number", n_rkd_354);
    }
}