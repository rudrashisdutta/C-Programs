#include<stdio.h>
int main()
{
    int m,sum=0,i,j;
    printf("Enter the dimension of the square matrix\n");
    scanf("%d",&m);
    int a[m][m];
    printf("Enter the elements of the sq matrix");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        if(i==j||(i+j)==(m-1))
        sum+=a[i][j];
    }
    printf("sum = %d",sum);
}