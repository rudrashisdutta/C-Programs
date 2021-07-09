#include<stdio.h>
void main()
{
    int n,i,j;
    printf("Enter the number of lines:\t");
    scanf("%d",&n);
    if(n%2==0)
    {
        for(i=1;i<=n/2;i++)
        {
            for(j=1;j<(n/2-i+1);j++)
            {
                printf("%d\t",j);                   
            }
        }
    }
}