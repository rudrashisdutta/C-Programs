//merge 2 sorted arrays
#include<stdio.h>
#include<stdlib.h>
void main()
{
int m,n,i,j,k,x;
repeat2:
printf("Enter the size of both the arrays\n");
scanf("%d%d",&m,&n);
int a[m],b[n],c[m+n];
printf("Enter the arrays in ascending order\n");
for(i=0;i<m;i++)
scanf("%d",&a[i]);
for(j=0;j<n;j++)
scanf("%d",&b[j]);
repeat:
repeat1:
printf("Press \n 1-merged array will be in ascending. \n 2- merged array will be in descending\n");
scanf("%d",&x);

if(x==1)
{k=0;
for(i=0,j=0;i<m&&j<n;)
{
if(a[i]<b[j])
c[k++]=a[i++];
else if(b[j]<a[i])
c[k++]=b[j++];
else if(a[i]==b[i])
{
c[k++]=a[i++];
c[k++]=b[j++];
}
}

if(i==m&&j!=n)
{ 
while(j<n)
c[k++]=b[j++];
}
else if(j==n&&i!=m)
{
while(i<m)
c[k++]=a[i++];
}

}

else if(x==2)
{k=m+n-1;
for(i=0,j=0;i<m&&j<n;)
{
if(a[i]<b[j])
c[k--]=a[i++];
else if(b[j]<a[i])
c[k--]=b[j++];
else if(a[i]==b[j])
{
c[k--]=a[i++];
c[k--]=b[j++];
}
}
if(i==m&&j<n)
{
while(j<n)
c[k--]=b[j++];
}
if(j==n&&i<m)
{
while(i<m)
c[k--]=a[i++];
}
}

else
{
printf("invalid entry");
goto repeat;
}
printf("The merged array is\n");
for(i=0;i<(m+n);i++)
printf("%d\t",c[i]);

int y;
repeat0:
printf("Press\n1-Try something else on the same array.\n2-operate on a different number\n3-exit");
scanf("%d",&y);

if(y==1)
goto repeat1;
else if(y==2)
goto repeat2;
else if(y==3)
goto end;
else
goto repeat0;
end:
exit(0);
}
