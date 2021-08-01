#include <stdio.h>
#include <time.h>
void isPrime(int x_rkd_354)
{
    int i_rkd_354 = 2, d_rkd_354 = 0;
    while (i_rkd_354 < x_rkd_354)
    {
        if (x_rkd_354 % i_rkd_354 == 0)
        {
            d_rkd_354 = 1;
            break;
        }
        i_rkd_354++;
    }
    printf("Number of comparisions:  %d\n\n", i_rkd_354 - 2);
    printf("%d is ", x_rkd_354);
    if (d_rkd_354 == 1 || x_rkd_354 == 1)
    {
        printf("not ");
    }
    printf("a prime number.");
}
void main()
{
    int x_rkd_354;
    clock_t t1 = clock();
    printf("Enter the number:  %ld", t1);
    scanf("%d", &x_rkd_354);
    isPrime(x_rkd_354);
    t1=clock();
    printf("Enter the number:  %ld", t1);
}