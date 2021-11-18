#include <stdio.h>
void swap_rd(int *x, int *y)
{
    int t = (*x);
    (*x) = (*y);
    (*y) = t;
}
void heapify(int arr_354[], int n, int i)
{
    int s_354 = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr_354[l] < arr_354[s_354])
    {
        s_354 = l;
    }
    if (r < n && arr_354[r] < arr_354[s_354])
    {
        s_354 = r;
    }
    if (s_354 != i)
    {
        swap_rd(&arr_354[i], &arr_354[s_354]);
        heapify(arr_354, n, s_354);
    }
}
void build_rd(int arr_354[], int n_354)
{
    for (int i_354 = (n_354 / 2) - 1; i_354 >= 0; i_354--)
    {
        heapify(arr_354, n_354, i_354);
    }
}
void printarr_rd(int arr_354[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d ", arr_354[i]);
    }
}
void main()
{
    int arr_354[] = {1, 9, 0, 6, 3, 5, 4};
    printf("Max heap:  ");
    build_rd(arr_354, 7);
    printarr_rd(arr_354, 7);
    // insert_rd(arr_354, &x_354);
    // insert_rd(arr_354, &x_354);
    // printarr_rd(arr_354, 7);
}