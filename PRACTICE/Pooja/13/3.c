#include<stdio.h>
void main()
{
    int i,j,m,n,a[100][100],c[100],d;
    printf("Enter the number of rows and columns of the matrix\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the matrix(0 and 1 only):\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            qwerty:
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0&&a[i][j]!=1)
            {
                printf("Wrong entry! please enter 0 or 1 only!\nENTER:  ");
                goto qwerty;
            }
        }
    }
    for(i=0;i<m;i++)
    {
        d=0;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            d++;
        }
        c[i]=d;
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<c[i];j++)
        printf("1");
        for(j=0;j<n-c[i];j++)
        printf("0");
        printf("\t\t%d\n",c[i]);
    }
}