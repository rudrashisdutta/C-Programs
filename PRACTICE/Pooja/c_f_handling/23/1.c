/*21.3*/
#include<stdio.h>
void main()
{
    int l=0,w=0,c=0;
    char str[1000],a,b;
    FILE *fe,*fo;
    fe=fopen("1.txt","w");
    printf("Enter the string:\n");
    scanf("%[^@]s",str);
    fprintf(fe,"%s",str);
    fclose(fe);
    fo=fopen("1.txt","r");
    while((a=fgetc(fo))!=EOF)
    {
        if(a!=' '&&a!='\n')
        c++;
        if(a=='\n'&&b!='\n')
        l++;
        if((a==' '||a=='\n')&&(b!=' '&&b!='\n'))
        w++;
        b=a;
    }
    if(w>0&&(b!=' '&&b!='\n'))
    w+=1;
    if(l>0&&b!='\n')
    l+=1;
    fclose(fo);
    printf("Number of:\nCharacters:  %d\nWords:  %d\nLines:  %d",c,w,l);
}