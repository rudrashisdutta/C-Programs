#include<stdio.h>
void main()
{
    char str[1000];
    printf("Enter a string:  ");
    gets(str);
    printf("The entered sting is:   ");
    puts(str);
    int i,x,y;
    for(i=1;str[i]!='\0';i++)
    {
        x=str[i-1];
        y=str[i];
        if(x==(y-1))
        {
            printf("\n\n%c and %c in position %d and %d are following the correct pattern.\n\n",str[i-1],str[i],i,i+1);
        }
    }
}