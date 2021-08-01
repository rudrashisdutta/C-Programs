#include<stdio.h>

int large(int *a,int *b,int *c,int *d,int *e){
    int larger = *a;
    if(larger<*b)
    larger = *b;
    if(larger<*c)
    larger = *c;
    if(larger<*d)
    larger = *d;
    if(larger<*e)
    larger = *e;
    return larger;
}

void main(){
    int a,b,c,d,e;
    printf("Enter the 5 number:\n");
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    printf("Largest:  %d",large(&a,&b,&c,&d,&e));
}