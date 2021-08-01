#include <stdio.h>
void gcd(int x_rkd_354, int y_rkd_354)
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
    gcd(a_rkd_354, b_rkd_354);
}
