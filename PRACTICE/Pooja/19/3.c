#include<stdio.h>
struct hotel
{
	char name[100],add[60];
	int charge,rooms,grade;
}h[100],f[100],temp[1];
void enter(int n)
{
int z;
	printf("Enter the details of the hotels:\n");
	for(int i=0;i<n;i++)
	{
		printf("\nEnter detailes of HOTEL %d:\nName:  ",i+1);
		scanf("%*c");
		gets(h[i].name);
		printf("\nAddress:  ");
		gets(h[i].add);
		printf("\nGrade:  ");
		scanf("%d",&h[i].grade);
		printf("\nPrice:  ");
		scanf("%d",&h[i].charge);
		printf("\nRooms Available:  ");
		scanf("%d",&h[i].rooms);
	}
}
void show(int n)
{
	printf("All Hotels Available:\n\n");
	for(int i=0;i<n;i++)
	{
		printf("%d)\nName:  %s\nGrade:  %d\nAddress:  ",i+1,h[i].name,h[i].grade);
		puts(h[i].add);
		printf("\nPrice(per room):  %d\nRooms Available:  %d\n\n",h[i].charge,h[i].rooms);
	}
}
void filter1(int n)
{
	int i,x,y=0,j=0,flag=0;
	s:
	printf("Enter the grade of which the hotels you want:  ");
	scanf("%d",&x);
	int k=0;
	for( i=0;i<n;i++)
	{
		if(h[i].grade==x)
		{
			f[j++]=h[i];
			y++;
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("SORRY:There are no hotels of this grade.\n");
		goto s;
	}
	for(i=0;i<y;i++)
	{
		for(j=0;j<y-i-1;j++)
		{
			if(f[i+1].charge<f[i].charge)
			{
				temp[k]=f[i];
				f[i]=f[i+1];
				f[i+1]=temp[k];
			}
		}
	}
	printf("Filter:\nGrade:  %d star\n\n",x);
	for(int i=0;i<y;i++)
	{
			printf("%d)\nName:  %s\nGrade:  %d\nAddress:  %s\nPrice(per room):  %d\nRooms Available:  %d\n\n",i+1,f[i].name,f[i].grade,f[i].add,f[i].charge,f[i].rooms);
	}
}
void filter2(int n)
{
	int x,flag=0;
	l:
	printf("Enter the maximum price you can pay:  ");
	scanf("%d",&x);
	printf("\n\nFilter:\nPrice <=  %d star\n\n",x);
	for(int i=0;i<n;i++)
	{
		if(h[i].charge<=x)
		{
			printf("%d)\nName:  %s\nGrade:  %d\nAddress:  %s\nPrice(per room):  %d\nRooms Available:  %d\n\n",i+1,h[i].name,h[i].grade,h[i].add,h[i].charge,h[i].rooms);
			flag=1;
		}
		else
		{
			flag=0;
			break;
		}
		if(flag==0)
		{
			printf("SORRY:There are no hotels under this price.\n");
			goto l;
		}
	}
}
void main()
{
	int n;
	printf("Enter the number of hotels:  ");
	scanf("%d",&n);
	enter(n);
	show(n);
	int g=0;
	p:
	printf("Filters available:\nPRESS:\n1)View hotels of entered grade\n2)View hotels under entered price\nAny key)Exit\n");
	scanf("%d",&g);
	if(g==1)
	filter1(n);
	else if(g==2)
	filter2(n);
	int f;
	printf("Do you want to try any other filter?\nPRESS:\n1 for YES\nANY KEY for NO\n\n");
	scanf("%d",&f);
	if(f==1)
	goto p;
	printf("Exiting program");
}