#include <stdio.h>
#include <time.h>
#include<math.h>
void isPrime1(int x_rkd_354)
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
int isPrime2(int n_rkd_354, int i_rkd_354)
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
            return isPrime2(n_rkd_354, i_rkd_354 - 1);
        }
    }
}
void isPrime3(int x_rkd_354)
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
    printf("Enter the number:  ");
    scanf("%d", &x_rkd_354);
    clock_t t;
    double countT;
    t = clock();
    isPrime1(x_rkd_354);
    t = clock() - t;
    countT=((double)t)/CLOCKS_PER_SEC;
    printf("\n\nPrime using while loop:  %f\n\n",countT);
    t = clock();
    isPrime3(x_rkd_354);
    t = clock() - t;
    countT=((double)t)/CLOCKS_PER_SEC;
    printf("\n\nPrime using square root:  %f\n\n",countT);
    printf("\n\nPrime using square root:  %lf\n\n",countT);
    int i_rkd_354 = x_rkd_354 / 2;
    t = clock();
    if (isPrime2(x_rkd_354, i_rkd_354) == 1)
    {
        printf("%d is prime number", x_rkd_354);
    }
    else
    {
        printf("%d is not prime number", x_rkd_354);
    }
    t = clock() - t;
    countT=((double)t)/CLOCKS_PER_SEC;
    printf("\n\nPrime using recursion:  %f\n\n",countT);
}