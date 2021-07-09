#include<stdio.h>
int large(int num1,int num2){
    if(num1>num2)
        return num1;
    else
        return num2;
}
void main(){
    int num1,num2;
    printf("Enter a number:\t");
    scanf("%d",&num1);
    printf("Enter another number:\t");
    scanf("%d",&num2);
    if(num1!=num2)
        printf("The largest number is:\t%d",large(num1,num2));
    else
        printf("The entered numbers are equal.");
}