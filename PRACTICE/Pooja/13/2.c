#include<stdio.h>
int main()
{
    int n,i,j,k,l,m,o,p;
    printf("Enter the highest number: ");
    scanf("%d",&n);
    if(n%2==0)
    {
        for(i=0;i<n-1;i++)
        {
            if(i<n/2)
            {
                for(j=1;j<=n/2-i;j++)
                printf("%d\t",j);
                for(k=0;k<n/2-j+1+i;k++)
                printf(" \t");
                for(l=j+k;l<=n;l++)
                printf("%d\t",l);
                printf("\n");
            }
            if(i>=n/2)
            {
                for(m=1;m<=i-n/2+2;m++)
                printf("%d\t",m);
                for(o=2*(n-i-2);o>0;o--)
                printf(" \t");
                for(p=n/2+n-i-1;p<=n;p++)
                printf("%d\t",p);
                printf("\n");
            }
        }
    }
    else 
    {
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                for(j=1;j<=n;j++)
                printf("%d\t",j);
                printf("\n");
            }
            else if(i<=n/2)
            {
                for(j=1;j<=n/2-i+1;j++)
                printf("%d\t",j);
                for(k=1;k<=2*i-1;k++)
                printf(" \t");
                for(l=n/2+i+1;l<=n;l++)
                printf("%d\t",l);
                printf("\n");
            }
            if(i==n-1)
            {
                for(m=1;m<=n;m++)
                printf("%d\t",m);
            }
            else if(i>n/2)
            {
                for(m=1;m<=2+(i-(n-n/2));m++)
                printf("%d\t",m);
                for(o=2*(n-i-2)+1;o>0;o--)
                printf(" \t");
                for(p=n/2+n-i;p<=n;p++)
                printf("%d\t",p);
                printf("\n");
            }
        }
    }
}