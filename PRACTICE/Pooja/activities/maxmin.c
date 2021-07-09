#include<stdio.h>
void maxmin(int n,int x,int y,int z)
{
    if(n==2)
        {   if(x>y&&x>z)
            printf("MAX=%d\n",x);
            else if(y>x&&y>z)
            printf("MAX=%d\n",y);
            else
            printf("MAX=%d\n",z);
        }    
    else
        {
            if(y<x&&y<z)
            printf("MIN=%d\n",y);
            if(z<x&&z<y)
            printf("MIN=%d\n",z);
            else
            printf("MIN=%d\n",x);
        }
}
int main()
{
    int x,y,z;
    printf("Enter the numbers");
    scanf("%d%d%d",&x,&y,&z);
    maxmin(2,x,y,z);
    maxmin(1,x,y,z);
}