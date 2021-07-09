#include<stdio.h>
void main()
{
    int a,b,*x,*y;
    printf("Enter the two values to be swapped:\n");
    scanf("%d%d",&a,&b);
    x=&a;
    y=&b;
    int temp,*t;
    t=&temp;
    *t=*x;
    *x=*y;
    *y=*t;
    printf("the swapped values are:\n%d\n%d",*x,*y);
}