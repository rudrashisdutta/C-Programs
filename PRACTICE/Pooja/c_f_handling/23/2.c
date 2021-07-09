#include<stdio.h>
void enter(int *i,int n)
{
    FILE *f;
    f=fopen("2.txt","w");
    for(;(*i)<n;(*i)++)
    {
        int p,nop;
        char name[100];
        printf("Enter the name of the book %d: ",(*i)+1);
        scanf("%*c");
        gets(name);
        printf("Enter the price of the book:  ");
        scanf("%d",&p);
        printf("Enter the number of pages of the book:  ");
        scanf("%d",&nop);
        fprintf(f,"|%20d|%30s|%20d|%20d|",(*i)+1,name,p,nop);
        if((*i)<(n-1))
        fprintf(f,"\n");
    }
    fclose(f);
}
void show(int i,int n)
{
    char a;
    FILE *f;
    f=fopen("2.txt","r");
    char b[100]="Book Number",p[100]="Price",no[100]="Number of Pages",na[100]="Name";
    printf("|%20s|%30s|%20s|%20s|",b,na,p,no);
    while((a=fgetc(f)!=EOF))
    {
        printf("%c",a);
    }
    fclose(f);
}
void main()
{
    int n,i=0;
    printf("Enter the number of books to be entered stored: ");
    scanf("%d",&n);
    enter(&i,n);
    show(0,n);
}