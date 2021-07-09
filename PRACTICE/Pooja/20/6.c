#include<stdio.h>
void cycle(int *ap,int n)
{
    int t,temp;
    t=*ap;
    for(int i=0;i<n-1;i++)
    *(ap+i)=*(ap+i+1);
    *(ap+n-1)=t;
}
void showm(int *ap,int n)
{
    for(int i=0;i<n;i++)
    printf("%d\t",*(ap+i));
}
void main()
{
    int n,i,a[100];
    printf("Enter the number of elements:  ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("::>\t");
    showm(a,n);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("::>\t");
        cycle(a,n);
        showm(a,n);
        printf("\n");
    }
}