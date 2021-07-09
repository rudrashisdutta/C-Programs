#include<stdio.h>
#include<string.h>
union abc
{
    int b;
    char a;
};
void main()
{
    union abc ob;
    ob.b=1088;
    printf("%d ",ob.b);
    ob.a='A';
    printf("%c ",ob.a);
    
    ob.b=1088;
    ob.a='A';
    printf("%c  %d",ob.a,ob.b);
}