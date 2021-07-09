#include<stdio.h>
void add(int *a,int *b,int *x,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            *(x+(i*n)+j)=*(a+(i*n)+j)+*(b+(i*n)+j);
        }
    }
}
void enter(int *a,int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",(a+(i*n)+j));
        }
    }
}
void main()
{
    int a[100][100],b[100][100],c[100][100],*x,*y,*z,m,n;
    x=a;
    y=b;
    z=c;
    printf("Enter the number of rows and columns of the matrices(MxN):\n");
    scanf("%d%d",&m,&n);
    printf("Enter the first matrix:\n");
    enter(x,m,n);
    printf("Enter the second matrix:\n");
    enter(y,m,n);
    add(x,y,z,m,n);
    printf("The added matrix is:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",*(z+(i*n)+j));
        }
        printf("\n");
    }
}