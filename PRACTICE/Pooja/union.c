#include<stdio.h>
int deletee(int x,int a[1000],int n)
{
    for(int i=n;i<x-1;i++)
    {
        a[i]=a[i+1];
    }
    x-=1;
    return x;
}
void unionm(int a[1000],int b[1000],int u[1000],int x,int y)
{
   for(int i=0;i<x;i++)
   {
       u[i]=a[i];
   } 
   for(int i=x,j=0;i<x+y,j<y;i++,j++)
   {
       u[i]=b[j];
   }
}
int inter(int a[1000],int b[1000],int in[1000],int m,int n)
{
	int i,j,k=0;
	for(i=0;i<m;i++)
	{
        {
            for(j=0;j<n;j++)
		    if(a[i]==b[j])  
            {
                in[k++]=a[i];
            }
        }
	}
    return k;
}
void equate(int m,int a[1000],int b[1000])
{
    for(int i=0;i<m;i++)
    {
        b[i]=a[i];
    }
}
void showm(int m,int a[1000])
{
    for(int i=0;i<m;i++)
    printf("%d\t",a[i]);
}
void enter(int m,int a[1000])
{
    for(int i=0;i<m;i++)
    scanf("%d",&a[i]);
}
void main()
{
    int m,n,x,y,a[1000],b[1000],u[1000],c[1000],d[1000],in[1000];
    printf("Enter the number of elements of the first set: ");
    scanf("%d",&m);
    printf("Enter the number of elements of the second set: ");
    scanf("%d",&n);
    printf("Enter the first set:\n");
    enter(m,a);
    equate(m,a,c);
    printf("Enter the second set:\n");
    enter(n,b);
    equate(n,b,d);
    x=m;
    y=n;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(c[i]==d[j])
            {
                y=deletee(y,d,j);
            }
        }
    }
    unionm(c,d,u,x,y);
    printf("The UNION of :\n");
    showm(m,a);
    printf("\nand\n");
    showm(n,b);
    printf("\nis\n");
    int p=x+y;
    showm(p,u);
    int k=inter(a,b,in,m,n);
    if(k>0)
    {
        printf("\n\nThe intersection of :\n");
        showm(m,a);
        printf("\nand\n");
        showm(n,b);
        printf("\nis\n");
        showm(k,in);
    }
    else 
    printf("\n\nThere are common elements in the sets\n Intersection set is an empty set.");
}