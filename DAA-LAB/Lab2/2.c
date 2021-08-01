#include <stdio.h>
#include <time.h>
void euclid_gcd(int x_rkd_354, int y_rkd_354)
{
    while (y_rkd_354 > 0)
    {
        int r_rkd_354 = x_rkd_354 % y_rkd_354;
        x_rkd_354 = y_rkd_354;
        y_rkd_354 = r_rkd_354;
    }
    printf("GCD = %d \n", x_rkd_354);
}
void consecutive_int_checking_gcd(int x_rkd_354, int y_rkd_354)
{
    int c_rkd_354;
    c_rkd_354 = x_rkd_354 >= y_rkd_354 ? y_rkd_354 : x_rkd_354;
    for (int i_rkd_354 = c_rkd_354; i_rkd_354 >= 1; i_rkd_354--)
    {
        if (x_rkd_354 % i_rkd_354 == 0 && y_rkd_354 % i_rkd_354 == 0)
        {
            printf("GCD = %d\n", i_rkd_354);
            break;
        }
    }
}
void middle_school_gcd(int x_rkd_354, int y_rkd_354)
{
    int c_rkd_354, ans_rkd_354 = 1, m_rkd_354, n_rkd_354;
    c_rkd_354 = x_rkd_354 >= y_rkd_354 ? y_rkd_354 : x_rkd_354;
    for (int i_rkd_354 = 2; i_rkd_354 < c_rkd_354; i_rkd_354++)
    {
        n_rkd_354 = 0;
        m_rkd_354 = 0;
        if (x_rkd_354 % i_rkd_354 == 0)
        {
            n_rkd_354 = 1;
            x_rkd_354 /= i_rkd_354;
        }
        if (y_rkd_354 % i_rkd_354 == 0)
        {
            m_rkd_354 = 1;
            y_rkd_354 /= i_rkd_354;
        }
        if (n_rkd_354 == 1 && m_rkd_354 == 1)
        {
            ans_rkd_354 *= i_rkd_354;
        }
        if (n_rkd_354 == 1 || m_rkd_354 == 1)
            i_rkd_354--;
    }
    printf("GCD = %d\n", ans_rkd_354);
}
void main()
{
    int a_rkd_354, b_rkd_354;
    printf("Enter the first number: ");
    scanf("%d", &a_rkd_354);
    printf("Enter the second number: ");
    scanf("%d", &b_rkd_354);
    clock_t t;
    double countT;
    t = clock();
    euclid_gcd(a_rkd_354, b_rkd_354);
    t = clock() - t;
    countT = ((double)t) / CLOCKS_PER_SEC;
    printf("\n\nEuclid's algorithm:  %f\n\n", countT);
    t = clock();
    consecutive_int_checking_gcd(a_rkd_354, b_rkd_354);
    t = clock() - t;
    countT = ((double)t) / CLOCKS_PER_SEC;
    printf("\n\nConsecutive Integer checking:  %f\n\n", countT);
    t = clock();
    middle_school_gcd(a_rkd_354, b_rkd_354);
    t = clock() - t;
    countT = ((double)t) / CLOCKS_PER_SEC;
    printf("\n\nMiddle school procedure:  %f\n\n", countT);
}