#include<stdio.h>
void count(long long int a,long long int *c)
{
    if(a!=0)
    {
        a/=10;
        (*c)++;
        count(a,c);
    }
}
void main()
{
    long long int a,c=0,*y;
    printf("Enter the number:  ");
    scanf("%lld",&a);
    y=&c;
    count(a,&c);
    printf("Number of digits: %d",c);
}