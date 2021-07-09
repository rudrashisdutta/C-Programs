#include<stdio.h>
void main()
{
    char str[100];
    FILE *f;
    f=fopen("test.txt","w");
    printf("Enter the string: ");
    gets(str);
    fprintf(f,"%s",str);
    fclose(f);
    char str2[100];
    FILE *fr;
    fr=fopen("test.txt","r");
    fgets(str2,100,fr);
    puts(str);
    fclose(fr);
}