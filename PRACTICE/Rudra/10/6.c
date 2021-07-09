#include<stdio.h>
void main()
{
    int a[10],*x,i;
    x=a;
    printf("Enter the 10 elements of the array\n");
    for(i=0;i<10;i++)
    scanf("%d",(x+i));
    printf("The 10 elements entered are:\n");
    for(int i=0;i<10;i++)
    printf("%d\t",*(x+i));
}