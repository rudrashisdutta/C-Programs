#include<stdio.h>
int main()
{
    char str[50];
    gets(str);
    
    int x;
    for(int i=0;str[i]!='\0';i++)
    {
        x=str[i];
        if(x>=65&&x<=90)
        str[i]+=32;
        else if(x>=97&&x<=122)
        str[i]-=32;
    }
    printf("%s",str);
}