//SECTION FULL PROGRAM
//NOTE Write a program to find larger of two numbers using function.
#include<stdio.h>
void greater(int a ,int b){
    if(a>b){
        printf("The first number is greater than the second.");
    }
    else if(b>a){
        printf("The second number is greater than the first.");
    }
    else{
        printf("Both the numbers are equal.");
    }
}
void main(){
    int a,b;
    printf("Enter the two number:\n");
    scanf("%d%d",&a,&b);
    greater(a,b);
}

//!SECTION FULL PROGRAM