#include<stdio.h>
void dsort(int *ap,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(*(ap+j)<*(ap+j+1))
            {
                temp=(*(ap+j));
                *(ap+j)=(*(ap+j+1));
                *(ap+j+1)=temp;
            }
        }
    }
}
void asort(int *ap,int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(*(ap+j)>*(ap+j+1))
            {
                temp=(*(ap+j));
                *(ap+j)=(*(ap+j+1));
                *(ap+j+1)=temp;
            }
        }
    }
}
void showm(int *ap,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d\t",*(ap+i));
}
void main()
{
    int i,n,a[100];
    printf("Enter the number of elements:  ");
    scanf("%d",&n);
    printf("Enter the elements of the array that is to b sorted:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\n\nThe entered array is:\n");
    showm(a,n);
    int y;
    printf("PRESS\n1: Ascending order\n2: Descending order\nAny Key: EXIT\n\nYour Choice:  ");
    scanf("%d",&y);
    if(y==1)
    {
        asort(a,n);
        printf("The array in ascending order is:\n");
        showm(a,n);
    }
    else if (y==2)
    {
        dsort(a,n);
        printf("The array in descending order is:\n");
        showm(a,n);
    }
    else
    {
        printf("_exiting_");
    }
}