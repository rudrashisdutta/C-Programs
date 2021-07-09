#include<stdio.h>
void swap(int a,int b){
    int temp;
    printf("a=%d\nb=%d",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("\nAfter swapping:\na=%d\nb=%d",a,b);
}
void main(){
    int a,b;
    printf("Enter the 2 numbers:\n");
    scanf("%d%d",&a,&b);
    swap(a,b);
}