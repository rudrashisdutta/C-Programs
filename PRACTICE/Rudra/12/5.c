#include<stdio.h>
void sum(int a,int b,int *s)
{
    if(a<=b)
    {
        *s+=a;
        a++;
        sum(a,b,s);
    }
}
void main()
{
    int a,b,s;
    printf("Enter the range: ");
    scanf("%d%d",&a,&b);
    s=0;
    if(a<b)
    sum(a,b,&s);
    else
    sum(b,a,&s);
    printf("sum: %d",s);
}