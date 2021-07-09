#include<stdio.h>
int main()
{
    char str[5000];
    int i,c=0;
    printf("Enter the strings:\n");
    scanf("%[^@]s",&str);
    for(int i=0;str[i]!='\0';i++)
    if(str[i]=='\n')
    c++;
    printf("Number of enters: %d",c);
}