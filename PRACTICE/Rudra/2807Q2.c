#include<stdio.h>
int sum(int num1,int num2){
    return num1+num2;
}
void main(){
    int num1,num2;
    printf("Enter a number:\t");
    scanf("%d",&num1);
    printf("Enter another number:\t");
    scanf("%d",&num2);
    printf("Sum of the numbers:\t%d",sum(num1,num2));
}