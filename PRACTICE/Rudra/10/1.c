#include<stdio.h>
void inc(int *a,int *b)
{
    ++(*a);
    ++(*b);
}
void main()
{
    int a,b;
    printf("Enter the numbers:\n");
    scanf("%d,%d",&a,&b);
    inc(&a,&b);
    printf("After increment of the number:\n%d %d",a,b);
}