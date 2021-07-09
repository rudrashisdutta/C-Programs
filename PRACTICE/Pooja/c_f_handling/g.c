#include<stdio.h>
struct stud
{
    int roll;
    char name[1000];
};
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
void filepr(char file[100],int x)
{
    FILE *f;
    printf("%-15s%-40s\n","Roll Number","Name");
    f=fopen(file,"r");
    for(int i=0;i<x;i++)
    {
        struct stud s;
        fscanf(f,"%d%s",&s.roll,s.name);
        printf("%-15d%-40s\n",s.roll,s.name);
    }
}
void main()
{
    ent(2,"P1.dat");
    filepr("P4.dat",5);
}