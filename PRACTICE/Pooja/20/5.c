#include<stdio.h>
void strrev(char *ap)
{
    int i,n=0;
    for(i=0;*(ap+i)!=0;i++)
    n++;
    for(i=n-1;i>=0;i--)
    printf("%c",*(ap+i));
}
void main()
{
    char str[100];
    printf("Enter the string whose reverse needs to be printed:  ");
    scanf("%s",str);
    printf("The reverse of the entered string is:\n");
    strrev(str);
}