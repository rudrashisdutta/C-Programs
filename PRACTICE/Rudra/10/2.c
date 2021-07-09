#include<stdio.h>
void main()
{
    int a=1,b=2,c=3,*x,*y,*z;
    x=&a;
    y=&b;
    z=&c;
    printf("Address of a:%p  Value of a: %d\nAddress of b:%p  Value of b: %d\nAddress of c:%p  Value of c: %d",&x,*x,&y,*y,&z,*z);
}