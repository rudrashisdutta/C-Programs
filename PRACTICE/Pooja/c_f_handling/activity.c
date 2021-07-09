#include<stdio.h>
#include<string.h>
struct stud
{
    int roll;
    char name[1000];
};
void del(struct stud s[1000],int *n)
{
    int i,j,m;
    for(i=0;i<*(n);i++)
    {
        m=0;
        for(j=0;j<*(n);j++)
        {
            if(s[i].roll==s[j].roll&&i!=j)
            {
                for(int k=j;k<*(n)-1;k++)
                {
                    strcpy(s[k].name,s[k+1].name);
                    s[k].roll=s[k+1].roll;
                    m++;        
                }
            }
        }
        *(n)-=m;
    }
}
void ent(int x,char file[100])
{
    FILE *f;
    struct stud t;
    f=fopen(file,"w");
    for(int i=0;i<x;i++)
    {
        printf("Enter the roll number:  ");
        scanf("%d",&t.roll);
        printf("Enter the name of the student with roll number %d:  ",t.roll);
        scanf("%*c");
        gets(t.name);
        fprintf(f,"%d\n%s\n",t.roll,t.name);
    }
    fclose(f);
}
void store(struct stud s[1000],int *x,int n,char file[100])
{
    int i;
    i=*x;
    FILE *f;
    n=*(x)+n;
    f=fopen(file,"r");
    for(;i<n;i++)
    {
        fscanf(f,"%d%[^\n]",&s[i].roll,s[i].name);
    }
    *(x)=i;
}
void fistore(struct stud s[1000],int x,char file[100])
{
    int i;
    FILE *f;
    f=fopen(file,"w");
    for(i=0;i<x;i++)
    {
        fprintf(f,"%d\n%s\n",s[i].roll,s[i].name);
    }
    fclose(f);
}
void filepr(char file[100],int x)
{
    FILE *f;
    printf("%-15s%-40s\n","Roll Number","Name");
    f=fopen(file,"r");
    for(int i=0;i<x;i++)
    {
        struct stud s;
        fscanf(f,"%d%[^\n]",&s.roll,s.name);
        printf("%-15d%-40s\n",s.roll,s.name);
    }
}
void main()
{
    struct stud s[1000];
    int n=0,n1,n2,n3,x=0;
    FILE *f4;
    printf("Enter the number of students to be stored in file 1:  ");
    scanf("%d",&n1);
    ent(n1,"P1.dat");
    printf("Enter the number of students to be stored in file 2:  ");
    scanf("%d",&n2);
    ent(n2,"P2.dat");
    printf("Enter the number of students to be stored in file 3:  ");
    scanf("%d",&n3);
    ent(n3,"P3.dat");
    store(s,&x,n1,"P1.dat");
    store(s,&x,n2,"P2.dat");
    store(s,&x,n3,"P3.dat");
    del(s,&x);
    fistore(s,x,"P4.dat");
    filepr("P4.dat",x);
}