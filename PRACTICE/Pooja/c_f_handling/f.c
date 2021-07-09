#include<stdio.h>
void main()
{
    FILE *fo,*fr;
    char ac,str[100],file[]="f.txt";
    int a=1,b=2,c=3,d,e,f;
    fo=fopen(file,"w");
    
    fprintf(fo,"%d,%d,%d",a,b,c);
    
    
    fclose(fo);
    fr=fopen("f.txt","r");
    fscanf(fr,"%d,%d,%d",&d,&e,&f);
    fclose(fr);
    printf("d=%d e=%d f=%d",d,e,f);
}