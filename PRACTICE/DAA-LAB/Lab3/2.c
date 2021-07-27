#include <stdio.h>

//O(n square and O(1) space)
void count_freq1(int n, int nums[])
{

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
            if (count >= (n / 2))
            {
                printf("yes\n");
                return;
            }
        }
    }
    printf("no\n");
}

// O(n) and O(1) extra space
void count_freq2(int n, int nums[])
{
    int count = 0;
    int candidate = -1;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == candidate)
            count++;
    }
    if (count >= (n / 2))
    {
        printf("yes\n");
    }
    else
        printf("no\n");
}
void main()
{
    int n;
    printf("Enter size of array:\n");
    scanf("%d", &n);
    int nums[100];
    printf("Enter the elements\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    count_freq1(n, nums);
    count_freq2(n, nums);
}