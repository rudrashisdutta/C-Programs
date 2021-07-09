#include<stdio.h>
void nat(int n,int i)
{
    while(i<=n)
    {
        printf("%d\t",i);
        i++;
    }
    nat(n,i);
}
void main()
{
    int n;
    printf("Enter the number of natural numbers you want to view:   ");
    scanf("%d",&n);
    printf("first %d natural numbers are :\n",n);
    nat(n,1);
}