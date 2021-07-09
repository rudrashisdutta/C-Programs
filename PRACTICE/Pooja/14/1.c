#include<stdio.h>
int main()
{
    char str[50];
    scanf("%*c");
    gets(str);
    int x,c1=0,c2=0;
    for(int i=0;str[i]!='\0';i++)
    {
        x=str[i];
        if(x>=65&&x<=90)
        c1++;
        else if(x>=97&&x<=122)
        c2++;
    }
    printf("Number of capital letters:\t%d\n",c1);
    printf("Number of small letters:\t%d",c2);
}