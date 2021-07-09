#include<stdio.h>
void op(int a,int b,int *sum,int *sub,int *mul,float *div)
{
    *sum=a+b;
    *sub=a-b;
    *div=(float)(a)/(float)(b);
    *mul=a*b;
}
void main()
{
    int a,b,sum,sub,mul;
    float div;
    printf("Enter the 2 numbers:\n");
    scanf("%d%d",&a,&b);
    op(a,b,&sum,&sub,&mul,&div);
    printf("Sum: %d\nSub: %d\nDiv: %f\nMul: %d",sum,sub,div,mul);
}