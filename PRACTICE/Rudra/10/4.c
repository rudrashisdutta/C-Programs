#include<stdio.h>
void largest(int *x,int n,int *large)
{
    *large=*x;
    int i;
    for(i=0;i<n;i++)
    {
        if(*large<*(x+i))
        *large=*(x+i);
    }
}
void main()
{
    int a[100],i,n,large,*x;
    x=a;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",(x+i));
    }
    largest(x,n,&large);
    printf("The largest element of the arrey is: %d",large);
}