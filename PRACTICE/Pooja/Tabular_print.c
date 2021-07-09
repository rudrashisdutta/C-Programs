#include<stdio.h>
#include<string.h>
int main()
{
	char str[50][50],g[50],roll[50][50],sec[50][50];
	int n,m1[50],m2[50],m3[50],tm[50];
	printf("Enter the number of students\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Enter the name of the student %d\n",(i+1));
		scanf("%*c");
		gets(str[i]);
		printf("Enter the roll number of student %d	\n",i+1);
		scanf("%*c");
		gets(roll[i]);
		printf("Enter the section of the student %d \n",i+1);
		scanf("%*c");
		gets(sec[i]);
		printf("Enter the marks in 3 subs of student %d\n",i+1);
		scanf("%d%d%d",&m1[i],&m2[i],&m3[i]);
		tm[i]=m1[i]+m2[i]+m3[i];
		int avg=tm[i]/3;
		if(avg>90&&avg<=100)
		g[i]='A';
		else if(avg>70&&avg<=90)
		g[i]='B';
		else if(avg>50&&avg<=70)
		g[i]='C';
		else if(avg>30&&avg<=50)
		g[i]='D';
		else
		g[i]='F';
	}
	printf("\n|%20s|%50s|%10s|%5s|%5s|%5s|%10s|%5s|\n","Roll number","Name","Section","Sub1","Sub2","Sub3","Tot_marks","Grade");
	for(int i=0;i<n;i++)
	{
		printf("|%20s|%50s|%10s|%5d|%5d|%5d|%10d|%5c|\n",roll[i],str[i],sec[i],m1[i],m2[i],m3[i],tm[i],g[i]);
	}
}