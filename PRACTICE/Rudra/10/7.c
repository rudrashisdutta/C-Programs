#include<stdio.h>
void sum(int *a,int m,int *s)
{
    int i;
    for(i=0;i<m;i++)
    *s+=*(a+i);
}
void main()
{
    int a[1000],m,s=0,*x;
    printf("Enter the size of the array: ");
    scanf("%d",&m);
    x=a;
    printf("Enter the elements of the array:\n");
    for(int i=0;i<m;i++)
    scanf("%d",(x+i));
    sum(x,m,&s);
    printf("Sum: %d",s);
}