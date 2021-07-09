#include<stdio.h>
int main()
{
    int a,b,count=0;
    printf("Enter the range:\nLower Limit:  ");
    scanf("%d",&a);
    printf("\nUpper Limit:  ");
    scanf("%d",&b);
    int j=0;
    for(int i=a;i<=b;i++)
    {
        int n=i,y=0,flag1=0,flag2=0;
        while(n!=0)
        {
            int d=n%10;
            y=y*10+d;
            n/=10;
        }
        if(i==y)
        flag1=1;
        int c=0;
        for(int j=i;j>0;j--)
        {
            if(i%j==0)
            c++;
        }
        if(c==2)
        flag2=1;
        if(flag1==1&&flag2==1)
        count++; 
    }
    printf("There are %d numbers which are both palindrome and prime.\n",count);
}    