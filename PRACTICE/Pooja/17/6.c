#include<stdio.h>
int maxi(int a[100],int large,int n,int i)
{
    while (i<n)
    {
        if(large<=a[i])
        {
            large=a[i];
        }
        i++;
        large=maxi(a,large,n,i);
    }
    return large;
}
int mini(int a[100],int small,int n,int i)
{
    while (i<n)
    {
        if(small>=a[i])
        {
            small=a[i];
        }
        i++;
        small=mini(a,small,n,i);
    }
    return small;
}
void main()
{
    int a[100],n,i,large,small;
    printf("Enter the number of elements:  ");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    large=a[0];
    small=a[0];
    large=maxi(a,large,n,0);
    small=mini(a,small,n,0);
    printf("Largest element:  %d\nSmallest element:  %d",large,small);
}