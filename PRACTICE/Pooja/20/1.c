#include<stdio.h>
void main()
{
    int a[100],n,*ap,sum=0;
    printf("Enter the number of elements:  ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    ap=a;
    for(int i=0;i<n;i++)
    sum+=(*(ap+i));
    printf("Sum = %d",sum);
}