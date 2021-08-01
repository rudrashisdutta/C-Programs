#include <stdio.h>
int square_root(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int ans = 0;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (mid * mid == n)
            return mid;
        if (mid * mid <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}
void main()
{
    int n;
    printf("Enter any +ve integer to find square root of n : ");
    scanf("%d", &n);
    printf("Square root of n = %d\n", square_root(n));
}