#include<stdio.h>
void main()
{
    int a[100],*ap,n,i;
    printf("Enter the number of elements:  ");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    ap=a;
    for(i=n-1;i>=0;i--)
    printf("%d\t",*(ap+i));
}