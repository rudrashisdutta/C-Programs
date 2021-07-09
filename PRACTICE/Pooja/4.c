#include<stdio.h>
int main()
{
    int m,i,j,flag=0;
    printf("Ënter the dimension of the sq matrix\n"); 
    scanf("%d",&m);
    int a[m][m];
    printf("Ënter the elements of the matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        scanf("%d",&a[i][j]);
    }
    printf("The matrix in matrix form is\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        printf("%d\t",a[i][j]);
        printf("\n");
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i==j&&a[i][j]!=1||i!=j&&a[i][j]!=0)
            flag=1;
        }
    }
    if(flag==1)
    printf("The entered matrix is not a unit matrix");
    else
    printf("The entered matrix is a unit matrix");
    
}