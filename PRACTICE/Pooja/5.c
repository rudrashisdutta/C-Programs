#include<stdio.h>
int main()
{
    int m,n,i,j;
    printf("Enter the dimensions of the matrix");
    scanf("%d%d",&m,&n);
    int a[m][n];
    printf("Enter the elements of the matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    printf("The matrix in matrix form is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("The transpose is\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        printf("%d\t",a[j][i]);
        printf("\n");
    }
}